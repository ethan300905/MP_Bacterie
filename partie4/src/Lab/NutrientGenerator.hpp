#pragma once
#include <SFML/Graphics.hpp>
#include <Random/Random.hpp>
#include "NutrientA.hpp"
#include "NutrientB.hpp"
#include<vector>
#include <Interface/Updatable.hpp>


class NutrientGenerator: public Updatable
{
public:
    NutrientGenerator();
    void update(sf::Time) override;
    void reset();

private:
    sf::Time time;

};

