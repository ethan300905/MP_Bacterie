#include "Nutrient.hpp"

Nutrient::Nutrient()
{
    Nutrient::Nutrient(Quantity quantity, Vec2d position)
    : position_(position),
      rayon_(quantity),
      quantity_(quantity)
    {}
}
