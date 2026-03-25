#pragma once
#include "Bacterium.hpp"
#include "Nutrient.hpp"
#include <SFML/Graphics.hpp>
#include "CircularBoundary.hpp"
#include "Utility/Vec2d.hpp"


class CultureDish:public CircularBoundary
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
    void update(sf::Time);
    void drawOn(sf::RenderTarget&);  //pas encore sur du void
    void changeTemperature(double delta);
    double getTemperature() const;
    void reset();


private:
    std::vector<Bacterium*> Bacteriums_;
    std::vector<Nutrient*> Nutrientsource_;
    double temperature_;
};

