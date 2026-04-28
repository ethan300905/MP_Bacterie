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
    amplitudeCounter_(uniform(0.,PI)),
    lastScore_(getAppEnv().getPositionScore(position, getIndex())),
    timeSinceLastTumble_(sf::Time::Zero)
 {
    addProperty("speed", getAppConfig()["monotrichous"]["speed"]);
    addProperty("lambda better", getAppConfig()["monotrichous"]["tumble"]["better"]);
    addProperty("lambda worse",getAppConfig()["monotrichous"]["tumble"]["worse"]);
}

j::Value const& MonotrichousBacterium::getConfig() const{

    return getAppConfig()["monotrichous"];
}

void MonotrichousBacterium::update(sf::Time dt){
    timeSinceLastTumble_ += dt;
    Bacterium::update(dt);
}

Vec2d MonotrichousBacterium::f(Vec2d position, Vec2d speed) const{
    return Vec2d(0,0);
}

Vec2d MonotrichousBacterium::getSpeedVector() const {
    return getDirection() * getProperty("speed").get();
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
    amplitudeCounter_ += 3 * dt.asSeconds();

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

    double score = getAppEnv().getPositionScore(getPosition(),getIndex());

    double lambda = 0.;
    if (score >= lastScore_){
        lambda = getProperty("lambda better").get();
    }else {
        lambda = getProperty("lambda worse").get();
    }
    double tumbleProbability = 1- exp( -timeSinceLastTumble_.asSeconds()/lambda);
    


    if(bernoulli(tumbleProbability)){
        timeSinceLastTumble_ = sf::Time::Zero;

        if (getAppConfig()["monotrichous"]["tumble"]["algo"].toString() == "single random vector"){
            setDirection(Vec2d::fromRandomAngle());
        } 
        else if(getAppConfig()["monotrichous"]["tumble"]["algo"].toString() == "best of N"){
            int N = 100;
            double bestScore = score; 
            Vec2d bestDirection = getDirection();

            for(int i = 0; i < N; ++i){
                Vec2d randomDir = Vec2d::fromRandomAngle();
                // On teste la position au prochain dt
                Vec2d testPos = getPosition() + randomDir * nextState.speed.length() * dt.asSeconds();
                double candidateScore = getAppEnv().getPositionScore(testPos, getIndex());
                
                if(candidateScore > bestScore){ // On compare au meilleur trouvé
                    bestScore = candidateScore;
                    bestDirection = randomDir;
                }
            }
            setDirection(bestDirection);
        }
    }

    lastScore_ = score; 

}

void MonotrichousBacterium::drawOn(sf::RenderTarget& target) const{
    Bacterium::drawOn(target);
    auto set_of_points = sf::VertexArray(sf::PrimitiveType::TriangleStrip);
    set_of_points.append({{0,0}, getColor().MutableColor::getColor()});
    for(int i(1); i<= 30; ++i){
        float x = static_cast<float>(-i* getRadius()/10.f);
        float y = static_cast<float>(getRadius() * sin(amplitudeCounter_) * sin(2*i / 10.0));
        set_of_points.append({{x,y}, getColor().MutableColor::getColor()});
        
        float offset_y = static_cast<float>(2+(getRadius() * sin(amplitudeCounter_) * sin(2*i / 10.0)));
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
