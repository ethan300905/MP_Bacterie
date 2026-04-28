#include "CultureDish.hpp"
#include "Application.hpp"
#include "Utility/Utility.hpp"
#include "Utility/Types.hpp"
#include <algorithm>


CultureDish::CultureDish(Vec2d position, double rayon)
    : CircularBoundary(position,rayon)

{
 temperature_ = getAppConfig()["culture dish"]["temperature"]["default"].toDouble();
 puissance_ = (getAppConfig()["culture dish"]["gradient"]["exponent"]["max"].toDouble() + getAppConfig()["culture dish"]["gradient"]["exponent"]["min"].toDouble())/2;

}

CultureDish::~CultureDish(){
    reset();
}

//(méthode)faire évoluer les bactéries ici:
//le type bool permet de savoir si la bactérie ou le nutriment a bien été ajouté
bool CultureDish::addBacterium(Bacterium* bacteria){
    if(this->contains(*bacteria)) {
        Bacteriums_.push_back(bacteria);
        return true;
    }
    return false;
}
bool CultureDish::addNutrient(Nutrient* nutrient){
    if(this->contains(*nutrient) && (Nutrientsource_.size() < getAppConfig()["generator"]["nutrient"]["max"].toDouble())) {
        Nutrientsource_.push_back(nutrient);
        return true;
    }
    return false;
}


void CultureDish::update(sf::Time dt){

    for(auto& Nutrient : Nutrientsource_){
        Nutrient-> update(dt);
    }

    for(auto& Bacteria : Bacteriums_){
        Bacteria-> update(dt);
    }

// Remove and delete dead nutrients
    for(size_t i(0); i < Nutrientsource_.size(); ++i){
        if(Nutrientsource_[i]->getQuantity() <= 0){
            delete Nutrientsource_[i];
            Nutrientsource_[i] = nullptr;
        }
    }
    Nutrientsource_.erase(std::remove(Nutrientsource_.begin(), Nutrientsource_.end(), nullptr), Nutrientsource_.end());
    for(size_t i(0); i < Bacteriums_.size(); ++i){
        if(Bacteriums_[i]->getEnergy() <= 0){
            delete Bacteriums_[i];
            Bacteriums_[i] = nullptr;
        }
    }
    Bacteriums_.erase(std::remove(Bacteriums_.begin(), Bacteriums_.end(), nullptr), Bacteriums_.end());
}
void CultureDish::drawOn(sf::RenderTarget& targetWindow) const{
    sf:: Color color(255, 255, 255, 100);
    auto border = buildAnnulus(getPosition(), getRadius(), color, 25);
    targetWindow.draw(border);

    for ( auto const Nutrient : Nutrientsource_){
        Nutrient ->drawOn(targetWindow);
    }
    for ( auto const Bacteria : Bacteriums_){
        Bacteria ->drawOn(targetWindow);
    }
}

void CultureDish::changeTemperature(double delta){
    if ((getAppConfig()["culture dish"]["temperature"]["min"].toDouble() <= (temperature_ + delta)) &&
         (temperature_ + delta) <= getAppConfig()["culture dish"]["temperature"]["max"].toDouble()){
    temperature_ += delta;
    /*}else if ((temperature_ + delta) > getAppConfig()["culture dish"]["temperature"]["max"].toDouble()){
        temperature_ = getAppConfig()["culture dish"]["temperature"]["max"].toDouble();
    }*/ // peut-etre si nombre permet pas d'aller au max car pas multiple le force 99 + 2 pas possible mais quand même à 100 ???
    }
}

void CultureDish::changeGradientexponent(double delta){
    if ((getAppConfig()["culture dish"]["gradient"]["exponent"]["min"].toDouble() <= (puissance_ + delta)) &&
         (puissance_ + delta) <= getAppConfig()["culture dish"]["gradient"]["exponent"]["max"].toDouble()){
    puissance_ += delta;
    }
}

void CultureDish::resetTemperature(){
    temperature_ = getAppConfig()["culture dish"]["temperature"]["default"].toDouble();
}

void CultureDish::resetGradientExponent(){
    puissance_ = (getAppConfig()["culture dish"]["gradient"]["exponent"]["max"].toDouble() + getAppConfig()["culture dish"]["gradient"]["exponent"]["min"].toDouble())/2;
}

double CultureDish::getTemperature() const{
    return temperature_;
}

double CultureDish::getGradientExponent() const{
    return puissance_;
}

void CultureDish::reset(){
    for (auto& bacterie : Bacteriums_){
        delete bacterie;      
    }
    for (auto& nutrient : Nutrientsource_){
        delete nutrient;
    }
    Nutrientsource_.clear();
    Bacteriums_.clear();
}


void CultureDish::checkCollidingNutriment(Bacterium* bacteria) const{
    if (!bacteria -> getIsAbstinent()){
        if(bacteria->TimeSinceLastMeal() > sf::seconds(bacteria->getConfig()["meal"]["delay"].toDouble())){
            for(auto& nutrient:Nutrientsource_){
                if (nutrient->isColliding(*bacteria)){
                    bacteria->resetTimeSinceLastMeal();
                    const Quantity maxMeal = bacteria->getConfig()["meal"]["max"].toDouble();
                    const Quantity maxEnergy = bacteria->getConfig()["energy"]["max"].toDouble();
                    const Quantity missingEnergy = std::max(0.0, maxEnergy - bacteria->getEnergy());
                    const Quantity amountEatable = std::min(maxMeal, missingEnergy);

                    Quantity amountEaten = nutrient->takeQuantity(amountEatable);
                    bacteria->addEnergy(amountEaten);
                    return;
                }
            }
        }
    }
}



double CultureDish::getPositionscore(const Vec2d& p){

    double score(0.);
    for(auto& nutrient: Nutrientsource_){
        score += nutrient -> getQuantity() / pow(distance(p, nutrient -> getPosition()), puissance_);
    }
    return score;
}





