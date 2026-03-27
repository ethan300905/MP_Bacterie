#include "Nutrient.hpp"
#include "Laboratory.hpp"
#include "Application.hpp"
#include "Utility/Utility.hpp"

Nutrient::Nutrient(const Quantity& quantity, Vec2d positionNutrient)
    : CircularBoundary(positionNutrient,quantity),
      quantityNutrient_(quantity),
      positionNutrient_(positionNutrient)

{
    index_=getAppEnv().getCurrentDishId();
}

Quantity Nutrient::takeQuantity(Quantity quantityTaken){

    if(quantityTaken < 0){  // if the quantity asked to be removed is negative : remove 0
        return 0;

    }else if (quantityTaken <= quantityNutrient_){
    quantityNutrient_-=quantityTaken;

    }else if (quantityTaken> quantityNutrient_){   // if the quantity asked to be removed is bigger than the actual quantity: remove actual quantity
        quantityNutrient_-=quantityNutrient_;
        return quantityNutrient_;
    }
        return quantityTaken;
}

void Nutrient::setQuantity(Quantity quantity){

    if (quantity<0){
        quantityNutrient_=0;
    }else {
        quantityNutrient_=quantity;
        setRadius(quantity);
    }


}

void Nutrient::drawOn(sf::RenderTarget& target) const{

    auto nutrientSprite = buildSprite(positionNutrient_,getRadius(), getAppTexture(getConfig()["texture"].toString()));
    target.draw(nutrientSprite);
}

j::Value const& Nutrient::getConfig() const{

    return getAppConfig()["nutriments"];
}
