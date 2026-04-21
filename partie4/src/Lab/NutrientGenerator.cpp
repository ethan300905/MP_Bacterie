#include "NutrientGenerator.hpp"
#include "Application.hpp"


NutrientGenerator::NutrientGenerator()
    : time(sf::Time::Zero) {}


void NutrientGenerator::update(sf::Time dt){
    time += dt;
    if(time > sf::seconds(getAppConfig()["generator"]["nutrient"]["delay"].toDouble())){
        time = sf::Time::Zero;
        if(bernoulli(getAppConfig()["generator"]["nutrient"]["prob"].toDouble()) == 1){
            Vec2d taille = getApp().getLabSize();
            double Pos_x = normal(taille.x()/2, taille.x()/4 * taille.x()/4);
            double Pos_y = normal(taille.y()/2, taille.y()/4 * taille.y()/4);
            Vec2d position(Pos_x,Pos_y);

            double minA = getAppConfig()["nutrients"]["A"]["quantity"]["min"].toDouble();
            double maxA = getAppConfig()["nutrients"]["A"]["quantity"]["max"].toDouble();
            Quantity quantity = uniform(minA, maxA);

            getAppEnv().addNutrient(new NutrientA(quantity, position));
        }else{
            Vec2d taille = getApp().getLabSize();
            double Pos_x = normal(taille.x()/2, taille.x()/4 * taille.x()/4);
            double Pos_y = normal(taille.y()/2, taille.y()/4 * taille.y()/4);
            Vec2d position(Pos_x,Pos_y);

            double minB = getAppConfig()["nutrients"]["B"]["quantity"]["min"].toDouble();
            double maxB = getAppConfig()["nutrients"]["B"]["quantity"]["max"].toDouble();
            Quantity quantity = uniform(minB, maxB);

            getAppEnv().addNutrient(new NutrientB(quantity, position));
        }
    }
}

void NutrientGenerator::reset(){
    time = sf::Time::Zero;
}
