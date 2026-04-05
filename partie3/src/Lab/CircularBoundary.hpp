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


    const Vec2d& getPosition() const;

    double getRadius() const;

    void move(const Vec2d&);
    bool contains(const CircularBoundary&) const;
    bool isColliding(const CircularBoundary&) const;
    bool contains(const Vec2d&) const;

    bool operator>(const CircularBoundary&) const;
    bool operator&(const CircularBoundary&) const;

    bool operator>(const Vec2d&) const;
protected :
    CircularBoundary(Vec2d, double);
    CircularBoundary(const CircularBoundary&) = default;
    CircularBoundary& operator=(const CircularBoundary&) = default;
    void setPosition(Vec2d);
    void setRadius(double);
private:
    Vec2d position_;
    double rayon_;

};

std::ostream& operator<<(std::ostream&, const CircularBoundary&);

