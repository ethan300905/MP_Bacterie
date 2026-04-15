#pragma once
#include <array>
#include "MutableNumber.hpp"
#include "Utility/Utility.hpp"

class MutableColor
{
public:
    MutableColor(j::Value const&);
    void mutate();
    sf::Color getColor();
private:
    std::array<MutableNumber,4> RGBA_;

};

