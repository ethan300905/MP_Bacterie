#include "Culturedish.hpp"



CultureDish::CultureDish(Vec2d position, double rayon)
    : CircularBoundary(position,rayon ),
      rayon_(rayon)
{

}

//(méthode)faire évoluer les bactéries ici:
//le type bool permet de savoir si la bactérie ou le nutriment a bien été ajouté
bool CultureDish::addBacterium(Bacterium*){

}
bool CultureDish::addNutrient(Nutrient*){

}
void CultureDish::update(sf::Time dt){

}
void CultureDish::drawOn(sf::RenderTarget& targetWindow){  //pas encore sur du void

}
