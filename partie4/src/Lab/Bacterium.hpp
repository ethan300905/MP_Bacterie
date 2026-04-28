#pragma once
#include <Interface/Drawable.hpp>
#include <Interface/Updatable.hpp>
#include <Lab/CircularBoundary.hpp>
#include <Utility/Vec2d.hpp>
#include <Utility/MutableColor.hpp>
#include "../Utility/Types.hpp"
#include <Utility/MutableNumber.hpp>
#include "Utility/DiffEqSolver.hpp"

typedef double Radians;

class Bacterium: public CircularBoundary, public Drawable, public Updatable, public DiffEqFunction
{
public:

    Bacterium(const Quantity&, const Vec2d&, Vec2d, const Quantity& , MutableColor);
    virtual ~Bacterium() = default;

    virtual void update(sf::Time) override;
    virtual void drawOn(sf::RenderTarget&) const override;

    virtual void move(sf::Time) = 0;
    virtual j::Value const& getConfig() const = 0;

    void mutate();
    void addProperty(const std::string& key, MutableNumber value);
    MutableNumber getProperty(const std::string&) const;

    // Utilitaire
    bool isDead() const;
    void consumeEnergy(Quantity);

    // Getters
    bool getIsAbstinent() const;
    sf::Time TimeSinceLastMeal() const;
    Quantity getEnergy() const;
    Vec2d getDirection() const;
    size_t getIndex() const;
    MutableColor getColor() const;

    // Setters
    void resetTimeSinceLastMeal();
    void addEnergy(Quantity);
    void setDirection(Vec2d);
    void addAngle_Dir(Radians);

protected:
    Radians getAngle_dir() const;

private:

    Quantity energy_;
    MutableColor color_;
    Vec2d direction_;
    bool isAbstinent_;
    std::map<std::string, MutableNumber> parameters_;
    size_t index_;
    sf::Time timeSinceLastMeal_;
    Radians angle_direction_;

};


