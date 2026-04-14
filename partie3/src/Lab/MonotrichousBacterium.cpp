#include "MonotrichousBacterium.hpp"
#include "Application.hpp"

MonotrichousBacterium::MonotrichousBacterium(const Quantity& energy, const Vec2d& position, Vec2d direction, const Quantity& rayon , MutableColor color)
    : Bacterium(energy, position, direction, rayon, color)
{

}

j::Value const& MonotrichousBacterium::getConfig() const{

    return getAppConfig()["monotrichous"];
}
