#include "Nutrient.hpp"
#include "Laboratory.hpp"
#include "Application.hpp"
#include "Utility/Utility.hpp"

Nutrient::Nutrient(const Quantity& quantity, Vec2d positionNutrient)
    : CircularBoundary(positionNutrient,quantity),
      quantityNutrient_(quantity)

{
    index_=getAppEnv().getCurrentDishId();
}

//Delete quand il arrive 0
Quantity Nutrient::takeQuantity(Quantity quantityTaken){
    Quantity actuallyTaken(0);

    if(quantityTaken < 0){  // if the quantity asked to be removed is negative : remove 0
        return 0;

    }else if (quantityTaken <= quantityNutrient_){
        actuallyTaken = quantityTaken;
    quantityNutrient_-=actuallyTaken;

    }else{ // if the quantity asked to be removed is bigger than the actual quantity: remove actual quantity
        actuallyTaken = quantityNutrient_;
        quantityNutrient_ = 0;
    }
    setQuantity(quantityNutrient_);
        return actuallyTaken;
}

void Nutrient::setQuantity(Quantity quantity){

    if (quantity<=0){
        quantityNutrient_=0;
        setRadius(0);
    }else {
        quantityNutrient_=quantity;
        setRadius(quantity);
    }


}

Quantity Nutrient::getQuantity() const{
    return quantityNutrient_;
}

void Nutrient::drawOn(sf::RenderTarget& target) const{
    auto const& texture = getAppTexture(getConfig()["texture"].toString());
    auto nutrientSprite = buildSprite(getPosition(),getRadius(), texture);
    target.draw(nutrientSprite);

    if(isDebugOn()){
        Vec2d deplacement = Vec2d(0,-50);
        int size =getRadius();
        auto const text = buildText(std::to_string(size),getPosition()+deplacement,getAppFont(),15,sf::Color::Black,0);
        target.draw(text);
    }
}
/*
j::Value const& Nutrient::getConfig() const{

    return getAppConfig()["nutrients"];
}
*/

void Nutrient::update(sf::Time dt){


    double speed = getConfig()["growth"]["speed"].toDouble();
    auto growth = speed * dt.asSeconds();
    double minTemp = getConfig()["growth"]["min temperature"].toDouble();
    double maxTemp = getConfig()["growth"]["max temperature"].toDouble();
    Quantity maxQuantity = getConfig()["quantity"]["max"].toDouble();

    if((minTemp <= getAppEnv().getTemperature(index_))&&( getAppEnv().getTemperature(index_)<= maxTemp) && (quantityNutrient_ <= maxQuantity*2) && (getAppEnv().contains(index_,*this))){
      quantityNutrient_ += growth;
      setQuantity(quantityNutrient_);
    }
}
