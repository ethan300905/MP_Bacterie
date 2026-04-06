#include "NutrientA.hpp"
#include "Application.hpp"

NutrientA::NutrientA(const Quantity& quantity, Vec2d positionNutrient)
    : Nutrient(quantity, positionNutrient) {}

j::Value const& NutrientA::getConfig() const{

    return getAppConfig()["nutrients"]["A"];
}
