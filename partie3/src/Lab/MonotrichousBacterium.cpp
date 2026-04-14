#include "MonotrichousBacterium.hpp"
#include "Application.hpp"

MonotrichousBacterium::MonotrichousBacterium(Vec2d position, double rayon , MutableColor color, Vec2d direction, Quantity energy)
    : Bacterium(position, rayon, color, direction, energy)
{

}

j::Value const& MonotrichousBacterium::getConfig() const{

    return getAppConfig()["monotrichous"];
}
