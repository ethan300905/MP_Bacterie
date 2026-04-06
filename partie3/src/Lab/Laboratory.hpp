#pragma once
#include "CultureDish.hpp"
#include<vector>
#include "NutrientGenerator.hpp"



class Laboratory
{
public:
    Laboratory();
    Laboratory(const Laboratory&) = delete;
    Laboratory& operator=(const Laboratory&) = delete;
    void nextDish();
    void previousDish();
    size_t getCurrentDishId() const;
    void increaseTemperature();
    void decreaseTemperature();
    double getTemperature() const;
    double getTemperature(size_t) const;
    void reset();
    void resetControls();
    void drawOn(sf::RenderTarget&);
    void update(sf::Time);
    void addNutrient(Nutrient*);
    bool contains(size_t, const CircularBoundary&) const;
private:
    std::vector<CultureDish*> CultureDishes_;
    size_t indice_;
    NutrientGenerator nutrientgenerator;

};

