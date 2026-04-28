#include "Laboratory.hpp"
#include "Config.hpp"
#include "Application.hpp"



Laboratory::Laboratory()
   : indice_(0)
{

    for(size_t i(0); i < getShortConfig().culture_dishes_number; ++i){
        Vec2d center = getApp().getCentre();
        double rayon = (getApp().getLabSize().x() * 0.95)/2;

        CultureDishes_.push_back(new CultureDish(center, rayon));
    }


}

void Laboratory::nextDish() {
    if (indice_ + 1 < CultureDishes_.size()){
        indice_++;
    }else{
        indice_= 0;
    }

}
void Laboratory::previousDish() {
    if (indice_ == 0){
        indice_ = CultureDishes_.size() - 1;
    }else{
        indice_--;
    }
}
size_t Laboratory::getCurrentDishId() const{
    return indice_;
}

void Laboratory::increaseTemperature(){
    (CultureDishes_[indice_])->changeTemperature(getAppConfig()["culture dish"]["temperature"]["delta"].toDouble());
}

void Laboratory::decreaseTemperature(){
    (CultureDishes_[indice_])->changeTemperature(-getAppConfig()["culture dish"]["temperature"]["delta"].toDouble());
}

double Laboratory::getTemperature() const{
    return CultureDishes_[indice_]->getTemperature();
}

double Laboratory::getTemperature(size_t index) const {
    return CultureDishes_[index]->getTemperature();
}

void Laboratory::decreaseGradientExponent(){
    (CultureDishes_[indice_])->changeGradientexponent(-getAppConfig()["culture dish"]["gradient"]["exponent"]["delta"].toDouble());
}

void Laboratory::increaseGradientExponent(){
    (CultureDishes_[indice_])->changeGradientexponent(getAppConfig()["culture dish"]["gradient"]["exponent"]["delta"].toDouble());
}

double Laboratory::getGradientExponent() const{
    return CultureDishes_[indice_]->getGradientExponent();
}

double Laboratory::getGradientExponent(size_t index) const {
    return CultureDishes_[index]->getGradientExponent();
}

void Laboratory::reset(){
    CultureDishes_[indice_]->reset();
    resetControls();
    nutrientgenerator.reset();
}
void Laboratory::resetControls(){
    CultureDishes_[indice_] -> resetTemperature();
    CultureDishes_[indice_] -> resetGradientExponent();
}
void Laboratory::drawOn(sf::RenderTarget& target) const{
    CultureDishes_[indice_] ->drawOn(target);
}

void Laboratory::update(sf::Time time){
    for(auto& dish:CultureDishes_){
        dish -> update(time);
    }
    nutrientgenerator.update(time);
}
void Laboratory::addNutrient(Nutrient* nutrient){

    if(!CultureDishes_[indice_]->addNutrient(nutrient)){
        delete nutrient;
        nutrient = nullptr;
    }
}
void Laboratory::addBacterium(Bacterium* bacteria){

    if(!CultureDishes_[indice_]->addBacterium(bacteria)){
        delete bacteria;
        bacteria = nullptr;
    }
}

bool Laboratory::contains(size_t index, const CircularBoundary& autre) const{
    return CultureDishes_[index] -> contains(autre);
}

bool Laboratory::doesCollideWithDish(size_t index, const CircularBoundary& body) const{
    return !CultureDishes_[index] -> contains(body);
}

bool Laboratory::doesCollideWithDish(size_t index, const Vec2d& point) const{
    return !CultureDishes_[index] -> contains(point);
}

void Laboratory::checkCollidingNutriment(size_t index, Bacterium* bacterium) const{
    CultureDishes_[index] -> checkCollidingNutriment(bacterium);
}

double Laboratory::getPositionScore (const Vec2d& p, size_t index){
    return CultureDishes_[index] -> getPositionscore(p);
}
