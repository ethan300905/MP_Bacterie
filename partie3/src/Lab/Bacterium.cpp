#include "Bacterium.hpp"
#include "Utility/Utility.hpp"
#include "Application.hpp"

Bacterium::Bacterium(Vec2d position, double rayon , MutableColor color, Vec2d direction, Quantity energy)
// parameters_() appelle le constructeur par défaut de map et l'initialise donc à vide, isAbstinent_ est initialisée par défaut à false.
   : CircularBoundary(position,rayon), color_(color), direction_(direction),
     isAbstinent_(false), energy_(energy), parameters_(), timeSinceLastMeal_(sf::Time::Zero)
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
    // A coder par Gab dans MutableColor : getColor() donnant une couleur reconnue par SFML de type sf::color
    //color à enlever après c'est juste pour que sa fonctionne
    sf:: Color color(255, 255, 255, 100);
    auto const circle = buildCircle(getPosition(), getRadius(), color);
    //                                                            ^ ici il faudra enlever color et mettre la fonction getColor() une fois codée

    target.draw(circle);

    if(isDebugOn()){
        Vec2d deplacement = Vec2d(0,-50);
        int size =getRadius();
        auto const text = buildText(std::to_string(size),getPosition()+deplacement,getAppFont(),15,sf::Color::Black,0);
        target.draw(text);
    }
    }

bool Bacterium::isDead() const { return (energy_ <= 0); }


bool Bacterium::getIsAbstinence() const{
    return isAbstinent_;
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
