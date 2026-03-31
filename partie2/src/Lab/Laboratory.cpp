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
    (CultureDishes_[indice_])->changeTemperature(1);
}

void Laboratory::decreaseTemperature(){
    (CultureDishes_[indice_])->changeTemperature(-1);
}

double Laboratory::getTemperature() const{
    return CultureDishes_[indice_]->getTemperature();
}

void Laboratory::reset(){
    CultureDishes_[indice_]->reset();
}
void Laboratory::resetControls(){

}
void Laboratory::drawOn(sf::RenderTarget& target){
    CultureDishes_[indice_] ->drawOn(target);
}

void Laboratory::update(sf::Time time){
    for(auto& dish:CultureDishes_){
        dish -> update(time);
    }
}
void Laboratory::addNutrient(Nutrient* nutrient){
    CultureDishes_[indice_] ->addNutrient(nutrient);
}

bool Laboratory::contains(const CircularBoundary& autre) const{
    return CultureDishes_[indice_] -> contains(autre);
}
