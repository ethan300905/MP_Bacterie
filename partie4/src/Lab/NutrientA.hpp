#pragma once
#include "Nutrient.hpp"


class NutrientA : public Nutrient
{
public:
    NutrientA(const Quantity&, Vec2d);
    j::Value const& getConfig() const override;
};


