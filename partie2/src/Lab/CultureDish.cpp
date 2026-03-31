#include "CultureDish.hpp"
#include "Application.hpp"
#include "Utility/Utility.hpp"
#include "Utility/Types.hpp"



CultureDish::CultureDish(Vec2d position, double rayon)
    : CircularBoundary(position,rayon)

{
 temperature_ = getAppConfig()["culture dish"]["temperature"]["default"].toDouble();
}
CultureDish::~CultureDish(){
    reset();
}
//(méthode)faire évoluer les bactéries ici:
//le type bool permet de savoir si la bactérie ou le nutriment a bien été ajouté
bool CultureDish::addBacterium(Bacterium*){

}
bool CultureDish::addNutrient(Nutrient* nutrient){

    if((this->contains(*nutrient))){

        Nutrientsource_.push_back(nutrient);
           return true;
    }else{
}

    return false;

}
void CultureDish::update(sf::Time dt){
    for(auto& Nutrient : Nutrientsource_){
        Nutrient-> update(dt);
    }

}
void CultureDish::drawOn(sf::RenderTarget& targetWindow){
    sf:: Color color(255, 255, 255, 100);
    auto border = buildAnnulus(getPosition(), getRadius(), color, 25);
    targetWindow.draw(border);

    for ( auto const Nutrient : Nutrientsource_){
        Nutrient ->drawOn(targetWindow);
    }  // à completer pour qu'il dessine les bacteries
}

void CultureDish::changeTemperature(double delta){
    if ((getAppConfig()["culture dish"]["temperature"]["min"].toDouble() <= (temperature_ + delta)) &&
         (temperature_ + delta) <= getAppConfig()["culture dish"]["temperature"]["max"].toDouble())
    temperature_ += delta;
}
void CultureDish::resetTemperature(){
    temperature_ = getAppConfig()["culture dish"]["temperature"]["default"].toDouble();
}
double CultureDish::getTemperature() const{
    return temperature_;
}

void CultureDish::reset(){
    for (auto& bacterie : Bacteriums_){
        delete bacterie;
        bacterie = nullptr;
    }
    for (auto& nutrient : Nutrientsource_){
        delete nutrient;
        nutrient = nullptr;
    }
    Nutrientsource_.clear();
    Bacteriums_.clear();
}
