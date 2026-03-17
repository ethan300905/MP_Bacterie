/*
 * Microbial cultures 2026
 * authors = ....
 */

#pragma once

#include <Utility/Vec2d.hpp>
#include <ostream>


/**
 *  @brief A circular boundary is defined by a radius and a position
 *
 *  @note radius must be >= 0.
 */
class CircularBoundary
{
public:

    CircularBoundary(Vec2d, double);
    CircularBoundary(const CircularBoundary&) = default;
    CircularBoundary& operator=(const CircularBoundary&) = default;
    const Vec2d& getPosition() const;
    void setPosition(Vec2d);
    double getRadius() const;
    void setRadius(double);
    void move(const Vec2d&);
    bool contains(const CircularBoundary& other) const;
    //bool isColliding(const CircularBoundary& other) const;


private:
    Vec2d position_;
    double rayon_;

};


