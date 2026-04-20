#include "Bacterium.hpp"
#include "Utility/Utility.hpp"
#include "Application.hpp"

Bacterium::Bacterium(const Quantity& energy, const Vec2d& position, Vec2d direction, const Quantity& rayon , MutableColor color)
// parameters_() appelle le constructeur par défaut de map et l'initialise donc à vide, isAbstinent_ est initialisée par défaut à false.
   : CircularBoundary(position,rayon), energy_(energy),  color_(color), direction_(direction),
     isAbstinent_(false), parameters_(), timeSinceLastMeal_(sf::Time::Zero)
{
    index_=getAppEnv().getCurrentDishId();
}


void Bacterium::update(sf::Time dt){
    timeSinceLastMeal_ += dt;
    move(dt);
    if(getAppEnv().doesCollideWithDish(index_, *this)){
        direction_ = -direction_;
    }

    getAppEnv().checkCollidingNutriment(index_, this);
}
void Bacterium::drawOn(sf::RenderTarget& target) const{


    auto const circle = buildCircle(getPosition(), getRadius(), color_.MutableColor::getColor());

    target.draw(circle);

    if(isDebugOn()){
        Vec2d deplacement = Vec2d(0,-50);
        int energy =getEnergy();
        auto const text = buildText(std::to_string(energy),getPosition()+deplacement,getAppFont(),15,sf::Color::Black,0);
        target.draw(text);
    }
    }

bool Bacterium::isDead() const { return (energy_ <= 0); }


bool Bacterium::getIsAbstinence() const{
    return isAbstinent_;
}

Vec2d Bacterium::getDirection() const{
    return direction_;
}

void Bacterium::setDirection(Vec2d direction ){
    direction_ = direction;
}

sf::Time Bacterium::TimeSinceLastMeal() const{
    return timeSinceLastMeal_;
}

void Bacterium::resetTimeSinceLastMeal(){
    timeSinceLastMeal_ = sf::Time::Zero;
}

void Bacterium::addEnergy(Quantity energy){
    energy_ += energy;
}

Quantity Bacterium::getEnergy() const {
    return energy_;
}

void Bacterium::consumeEnergy(Quantity qt){
    energy_ -= qt;
}


size_t Bacterium::getIndex() const{
    return index_;
}

// vscode ?
// qtc ?
