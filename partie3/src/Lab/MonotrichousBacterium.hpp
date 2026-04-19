#pragma once
#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"
#include <Random/Random.hpp>

class MonotrichousBacterium: public Bacterium, public DiffEqFunction
{
public:
    MonotrichousBacterium(const Vec2d&);
    j::Value const& getConfig() const override;
    void move(sf::Time) override;
    virtual Vec2d f(Vec2d position, Vec2d speed) const override;
    Vec2d getSpeedVector() const;
};


