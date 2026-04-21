#pragma once
#include "CultureDish.hpp"
#include<vector>
#include "NutrientGenerator.hpp"
#include <Interface/Drawable.hpp>
#include <Interface/Updatable.hpp>


class Laboratory:public Drawable, public Updatable
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
    void drawOn(sf::RenderTarget&) const override;
    void update(sf::Time) override;
    void addNutrient(Nutrient*);
    void addBacterium(Bacterium* );
    bool contains(size_t, const CircularBoundary&) const;
    bool doesCollideWithDish(size_t, const CircularBoundary&) const;
    bool doesCollideWithDish(size_t, const Vec2d&) const;
    void checkCollidingNutriment(size_t, Bacterium*) const;
private:
    std::vector<CultureDish*> CultureDishes_;
    size_t indice_;
    NutrientGenerator nutrientgenerator;

};

