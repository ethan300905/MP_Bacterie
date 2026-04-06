#pragma once
#include "Bacterium.hpp"
#include "Nutrient.hpp"
#include <SFML/Graphics.hpp>
#include "CircularBoundary.hpp"
#include "Utility/Vec2d.hpp"
#include <Interface/Drawable.hpp>
#include <Interface/Updatable.hpp>



class CultureDish:public CircularBoundary, public Drawable, public Updatable
{
public:
    CultureDish(Vec2d, double);
    CultureDish(const CultureDish&) = delete;
    CultureDish& operator=(const CultureDish&) = delete;
    ~CultureDish();

    //(méthode)faire évoluer les bactéries ici:
    //le type bool permet de savoir si la bactérie ou le nutriment a bien été ajouté
    bool addBacterium(Bacterium*);
    bool addNutrient(Nutrient*);
    void update(sf::Time) override;
    void drawOn(sf::RenderTarget&) const override;
    void changeTemperature(double delta);
    void resetTemperature();
    double getTemperature() const;

    void reset();
    size_t getNumberNutrients() const;

private:
    std::vector<Bacterium*> Bacteriums_;
    std::vector<Nutrient*> Nutrientsource_;
    double temperature_;
};

