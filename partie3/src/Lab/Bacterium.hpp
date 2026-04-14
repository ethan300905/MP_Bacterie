#pragma once
#include <Interface/Drawable.hpp>
#include <Interface/Updatable.hpp>
#include <Lab/CircularBoundary.hpp>
#include <Utility/Vec2d.hpp>
#include <Utility/MutableColor.hpp>
#include "../utility/Types.hpp"
#include <Utility/MutableNumber.hpp>

class Bacterium: public CircularBoundary, public Drawable, public Updatable
{
public:

    Bacterium(Vec2d, double, MutableColor, Vec2d, Quantity);
    virtual ~Bacterium() = default;

    virtual void update(sf::Time) override;
    virtual void drawOn(sf::RenderTarget&) const override;

    virtual void move(sf::Time) const = 0;
    virtual j::Value const& getConfig() const = 0;

    // Utilitaire
    bool isDead() const;

    // Getters
    bool getIsAbstinence() const;
    sf::Time TimeSinceLastMeal() const;

    // Setters
    void resetTimeSinceLastMeal();
    void addEnergy(Quantity);

private:

    MutableColor color_;
    Vec2d direction_;
    bool isAbstinent_;
    Quantity energy_;
    std::map<std::string, MutableNumber> parameters_;
    size_t index_;
    sf::Time timeSinceLastMeal_;

};


