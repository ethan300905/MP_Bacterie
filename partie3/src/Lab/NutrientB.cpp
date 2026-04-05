#include "NutrientB.hpp"
#include "Application.hpp"
NutrientB::NutrientB(const Quantity& quantity, Vec2d positionNutrient)
    : Nutrient(quantity, positionNutrient)
{

}
/*
void NutrientB::drawOn(sf::RenderTarget& target) const{
    Nutrient::drawOn(target);
}
void NutrientB::update(sf::Time dt){
    Nutrient::update(dt);
}
*/
j::Value const& NutrientB::getConfig() const{

    return getAppConfig()["nutrients"]["B"];
}
