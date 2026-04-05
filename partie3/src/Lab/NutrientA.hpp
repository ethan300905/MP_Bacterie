#ifndef NUTRIENTA_HPP
#define NUTRIENTA_HPP
#include "Nutrient.hpp"


class NutrientA : public Nutrient
{
public:
    NutrientA(const Quantity&, Vec2d);
    //void update(sf::Time) override;
    //void drawOn(sf::RenderTarget& target) const override;
    j::Value const& getConfig() const override;
};

#endif // NUTRIENTA_HPP
