#include "MonotrichousBacterium.hpp"
#include "Application.hpp"

MonotrichousBacterium::MonotrichousBacterium(const Vec2d& position)
: Bacterium(
    uniform(
        getAppConfig()["monotrichous"]["energy"]["min"].toDouble(),
        getAppConfig()["monotrichous"]["energy"]["max"].toDouble()
    ),
    position,
    Vec2d::fromRandomAngle(),
    uniform(
        getAppConfig()["monotrichous"]["radius"]["min"].toDouble(),
        getAppConfig()["monotrichous"]["radius"]["max"].toDouble()
    ),
    getAppConfig()["monotrichous"]["color"]
) {}

j::Value const& MonotrichousBacterium::getConfig() const{

    return getAppConfig()["monotrichous"];
}

Vec2d MonotrichousBacterium::f(Vec2d position, Vec2d speed) const{
    return Vec2d(0,0);
}

Vec2d MonotrichousBacterium::getSpeedVector() const {
    return getDirection() * 50.0; 
}

void MonotrichousBacterium::move(sf::Time dt){

    Vec2d currentPos = getPosition(); 
    Vec2d currentSpeed = getSpeedVector();
    DiffEqResult nextState = stepDiffEq(currentPos, currentSpeed, dt, *this);

    // Si la nouvelle position sort du plat, inverser et recalculer
    if(getAppEnv().doesCollideWithDish(getIndex(), nextState.position)){
        setDirection(-getDirection());
        currentSpeed = getSpeedVector(); // recalcul avec nouvelle direction
        nextState = stepDiffEq(currentPos, currentSpeed, dt, *this); // recalcul
    }

    Vec2d displacement = nextState.position - getPosition();
    if (displacement.lengthSquared() > 0.001) {
        this->CircularBoundary::move(displacement);
}
setDirection(nextState.speed.normalised());
consumeEnergy(displacement.length() * getAppConfig()["monotrichous"]["energy"]["consumption factor"].toDouble());

}