#pragma once
#include "Bacterium.hpp"

class MonotrichousBacterium: public Bacterium
{
public:
    MonotrichousBacterium(Vec2d, double, MutableColor, Vec2d, Quantity);
    j::Value const& getConfig() const override;
};


