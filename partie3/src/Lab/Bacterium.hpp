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

    Bacterium(const Quantity&, const Vec2d&, Vec2d, const Quantity& , MutableColor);
    virtual ~Bacterium() = default;

    virtual void update(sf::Time) override;
    virtual void drawOn(sf::RenderTarget&) const override;

    virtual void move(sf::Time) = 0;
    virtual j::Value const& getConfig() const = 0;

    // Utilitaire
    bool isDead() const;
    void consumeEnergy(Quantity);

    // Getters
    bool getIsAbstinence() const;
    sf::Time TimeSinceLastMeal() const;
    Quantity getEnergy() const;

    // Setters
    void resetTimeSinceLastMeal();
    void addEnergy(Quantity);

private:

    Quantity energy_;
    MutableColor color_;
    Vec2d direction_;
    bool isAbstinent_;
    std::map<std::string, MutableNumber> parameters_;
    size_t index_;
    sf::Time timeSinceLastMeal_;

};


