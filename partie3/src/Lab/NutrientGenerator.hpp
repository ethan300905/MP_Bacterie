#ifndef NUTRIENTGENERATOR_HPP
#define NUTRIENTGENERATOR_HPP
#include <SFML/Graphics.hpp>
#include <Random/Random.hpp>
#include "NutrientA.hpp"
#include "NutrientB.hpp"
#include<vector>
class NutrientGenerator
{
public:
    NutrientGenerator();
    void update(sf::Time);
    void reset();

private:
    sf::Time time;

};

#endif // NUTRIENTGENERATOR_HPP
