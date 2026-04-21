#include "NutrientB.hpp"
#include "Application.hpp"
NutrientB::NutrientB(const Quantity& quantity, Vec2d positionNutrient)
    : Nutrient(quantity, positionNutrient) {}

j::Value const& NutrientB::getConfig() const{

    return getAppConfig()["nutrients"]["B"];
}
