
#pragma once
#include <Lab/CircularBoundary.hpp>
#include <../Utility/Vec2d.hpp>
#include "../Utility/Types.hpp"
#include <SFML/Graphics.hpp>
#include <Interface/Drawable.hpp>
#include <Interface/Updatable.hpp>


class Nutrient:public CircularBoundary, public Drawable, public Updatable

{
public:
    Nutrient(const Quantity&, Vec2d);
    Quantity takeQuantity(Quantity);
    void setQuantity(Quantity);

    virtual j::Value const& getConfig() const = 0;
    Quantity getQuantity() const;

    virtual void update(sf::Time) override;
    virtual void drawOn(sf::RenderTarget& target) const override;

private:
    Quantity quantityNutrient_;
    size_t index_;
};

