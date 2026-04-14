#pragma once
#include "Bacterium.hpp"

class MonotrichousBacterium: public Bacterium
{
public:
    MonotrichousBacterium(const Quantity&, const Vec2d&, Vec2d, const Quantity& , MutableColor);
    j::Value const& getConfig() const override;
};


