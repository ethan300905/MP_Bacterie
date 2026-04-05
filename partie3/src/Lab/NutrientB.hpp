#ifndef NUTRIENTB_HPP
#define NUTRIENTB_HPP
#include "Nutrient.hpp"


class NutrientB: public Nutrient
{
public:
    NutrientB(const Quantity&, Vec2d);
    //void update(sf::Time) override;
   // void drawOn(sf::RenderTarget& target) const override;
    j::Value const& getConfig() const override;
};

#endif // NUTRIENTB_HPP
