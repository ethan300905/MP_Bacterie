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
    ),
    t(uniform(0.,PI))
 {}

j::Value const& MonotrichousBacterium::getConfig() const{

    return getAppConfig()["monotrichous"];
}

Vec2d MonotrichousBacterium::f(Vec2d position, Vec2d speed) const{
    return Vec2d(0,0);
}

Vec2d MonotrichousBacterium::getSpeedVector() const {
    return getDirection() * 25.0; 
}

void MonotrichousBacterium::move(sf::Time dt){

    Vec2d currentPos = getPosition(); 
    Vec2d currentSpeed = getSpeedVector();
    DiffEqResult nextState = stepDiffEq(currentPos, currentSpeed, dt, *this);
    //setPosition(nextState.position);
    // Si la nouvelle position sort du plat, inverser et recalculer
    if(getAppEnv().doesCollideWithDish(getIndex(), nextState.position)){

        setDirection(-getDirection());
        currentSpeed = getSpeedVector(); // recalcul avec nouvelle direction
        nextState = stepDiffEq(currentPos, currentSpeed, dt, *this); // recalcul
    }
    
    //else{
      //  setPosition(currentPos);
    //}

    Vec2d displacement = nextState.position - getPosition();
    if (displacement.lengthSquared() > 0.001) {
        this->CircularBoundary::move(displacement);
}
    t += 3 * dt.asSeconds();

    Vec2d nextDir = nextState.speed.normalised();
    Radians targetAngle = nextDir.angle();
    Radians currentAngle = getAngle_dir();

    auto const angleDiff = angleDelta(targetAngle, currentAngle);
    auto dalpha = PI * dt.asSeconds();
    dalpha = std::min(dalpha, std::abs(angleDiff));
    dalpha = std::copysign(dalpha, angleDiff); 
    addAngle_Dir(dalpha);
    setDirection(nextDir);

    consumeEnergy(displacement.length() * getAppConfig()["monotrichous"]["energy"]["consumption factor"].toDouble());

}

void MonotrichousBacterium::drawOn(sf::RenderTarget& target) const{
    Bacterium::drawOn(target);
    auto set_of_points = sf::VertexArray(sf::PrimitiveType::TriangleStrip);
    set_of_points.append({{0,0}, getColor().MutableColor::getColor()});
    for(double i(1); i<= 30; ++i){
        float x = static_cast<float>(-i* getRadius()/10.f);
        float y = static_cast<float>(getRadius() * sin(t) * sin(2*i / 10.0));
        set_of_points.append({{x,y}, getColor().MutableColor::getColor()});
        
        float offset_y = static_cast<float>(2+(getRadius() * sin(t) * sin(2*i / 10.0)));
        set_of_points.append({{x,offset_y}, getColor().MutableColor::getColor()});
    
    }

    auto transform = sf::Transform();

    transform.translate(getPosition());
    rotate_and_translate(transform,(getAngle_dir() / DEG_TO_RAD), static_cast<double>(-getRadius() + 2),0); 
    // puis:
    target.draw(set_of_points, transform); // dessin de l'ensemble des points
                                             // fait après leur transformation
                                             //selon la matrice transform
}