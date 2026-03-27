
#pragma once
#include <Lab/CircularBoundary.hpp>
#include <../Utility/Vec2d.hpp>
#include "../utility/Types.hpp"
#include <SFML/Graphics.hpp>


class Nutrient:public CircularBoundary

{
public:
    Nutrient(const Quantity&, Vec2d);
    Quantity takeQuantity(Quantity);
    void setQuantity(Quantity);
    void drawOn(sf::RenderTarget& target) const;
    j::Value const& getConfig() const;

private:
    Quantity quantityNutrient_;
    Vec2d positionNutrient_;
    size_t index_;
};

