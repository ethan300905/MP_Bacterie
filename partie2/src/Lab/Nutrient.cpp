#include "Nutrient.hpp"

Nutrient::Nutrient(Quantity quantity, Vec2d position)
    : CircularBoundary(position, quantity),
      quantity_(quantity)
    {}


