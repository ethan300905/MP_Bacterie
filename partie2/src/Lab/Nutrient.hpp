#ifndef NUTRIENT_HPP
#define NUTRIENT_HPP
#pragma once
#include <Lab/CircularBoundary.hpp>
#include <../Utility/Vec2d.hpp>
#include "../utility/Types.hpp"


class Nutrient :public CircularBoundary

{
public:

    Nutrient(Quantity, Vec2d);

private:
    Quantity quantity_;
};

#endif // NUTRIENT_HPP
