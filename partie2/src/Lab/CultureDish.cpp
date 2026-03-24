#include "CultureDish.hpp"
#include "Application.hpp"
#include "Utility/Utility.hpp"



CultureDish::CultureDish(Vec2d position, double rayon)
    : CircularBoundary(position,rayon)

{
 temperature_ = getAppConfig()["culture dish"]["temperature"]["default"].toDouble();
}
CultureDish::~CultureDish(){
    reset();
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
    sf:: Color color(255, 255, 255, 100);
    auto border = buildAnnulus(getPosition(), getRadius(), color, 25);
    targetWindow.draw(border);
}
void CultureDish::changeTemperature(double delta){
    temperature_ += delta;
}
double CultureDish::getTemperature() const{
    return temperature_;
}
void CultureDish::reset(){
    for (auto& bacterie : Bacteriums_){
        delete bacterie;
        bacterie = nullptr;
    }
    for (auto& nutrient : Nutrientsource_){
        delete nutrient;
        nutrient = nullptr;
    }
    Nutrientsource_.clear();
    Bacteriums_.clear();
}
