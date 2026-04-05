#include "NutrientA.hpp"
#include "Application.hpp"

NutrientA::NutrientA(const Quantity& quantity, Vec2d positionNutrient)
    : Nutrient(quantity, positionNutrient)
{

}
/*
void NutrientA::drawOn(sf::RenderTarget& target) const{
    Nutrient::drawOn(target);
}

void NutrientA::update(sf::Time dt){
    Nutrient::update(dt);
}*/
j::Value const& NutrientA::getConfig() const{

    return getAppConfig()["nutrients"]["A"];
}
