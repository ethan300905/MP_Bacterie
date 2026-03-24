#ifndef CULTUREDISH_HPP
#define CULTUREDISH_HPP
#include "Bacterium.hpp"
#include "Nutrient.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Application.hpp" //a voir quelles inclusions sont nécéssaires
#include "CircularBoundary.hpp"
#include "Utility/Utility.hpp"

class CultureDish:public CircularBoundary
{
public:
    CultureDish(Vec2d, double, double);
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

#endif // CULTUREDISH_HPP
