/*
 * POOSV 2026
 * authors : ....
 */

#include <Lab/CircularBoundary.hpp>


CircularBoundary::CircularBoundary(Vec2d position, double rayon)
    : position_(position),
      rayon_(rayon)
{}

const Vec2d& CircularBoundary::getPosition() const {
    return position_;
}

void CircularBoundary::setPosition(Vec2d position){
    position_=position;
}

double CircularBoundary::getRadius() const{
    return rayon_;
}

void CircularBoundary::setRadius(double rayon){
    rayon_=rayon;
}

void CircularBoundary::move(const Vec2d& deplacement){
    position_ += deplacement;
}

bool CircularBoundary::contains(const CircularBoundary& other) const {
    if((rayon_ >= other.getRadius())&& distance(this->position_, other.getPosition())<= (rayon_ - other.getRadius()))
    {
    return true;
    }
    return false;
}
