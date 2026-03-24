#ifndef CULTUREDISH_HPP
#define CULTUREDISH_HPP
#include "Bacterium.hpp"
#include "Nutrient.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Application.hpp" //a voir quelles inclusions sont nécéssaires

class CultureDish
{
public:
    CultureDish();
    //(méthode)faire évoluer les bactéries ici:
    //le type bool permet de savoir si la bactérie ou le nutriment a bien été ajouté
    bool addBacterium(Bacterium*){

    }
    bool addNutrient(Nutrient*){

    }
    void update(sf::Time dt){

    }
    void drawOn(sf::RenderTarget& targetWindow){  //pas encore sur du void

    }


private:
    std::vector<Bacterium> Bacteriums_;
    std::vector<Nutrient> Nutrientsource_;
    double temperature_;
};

#endif // CULTUREDISH_HPP
