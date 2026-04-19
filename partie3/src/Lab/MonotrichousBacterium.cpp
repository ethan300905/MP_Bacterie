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
    // Utilise explicitement le getter pour être sûr de la valeur
    return getDirection() * 5.0; 
}

void MonotrichousBacterium::move(sf::Time dt){
    Vec2d currentPos = getPosition(); 
    
    Vec2d currentSpeed = getSpeedVector();
    DiffEqResult nextState = stepDiffEq(currentPos, currentSpeed, dt, *this);
    Vec2d displacement = nextState.position - getPosition();
    //if (displacement.lengthSquared() > 0.001) {
        // On utilise le move de CircularBoundary avec le déplacement relatif
        this->CircularBoundary::move(displacement);
//}
setDirection(nextState.speed.normalised());
}