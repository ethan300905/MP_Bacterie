#pragma once
#include <Interface/Drawable.hpp>
#include <Interface/Updatable.hpp>

class Bacterium: public Drawable, public Updatable
{
public:
    Bacterium();
};

