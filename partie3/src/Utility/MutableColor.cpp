#include "MutableColor.hpp"

MutableColor::MutableColor(j::Value const& config)

{
RGBA_[0] = MutableNumber(config["r"]);
RGBA_[1] = MutableNumber(config["g"]);
RGBA_[2] = MutableNumber(config["b"]);
RGBA_[3] = MutableNumber(config["a"]);
}

void MutableColor::mutate(){
    for(auto& color:RGBA_){
        color.mutate();
    }
}

sf::Color MutableColor::getColor(){
#if SFML_VERSION_MAJOR >= 3
    return { static_cast<std::uint8_t>(mComponents[0].get() * 255),
             static_cast<std::uint8_t>(mComponents[1].get() * 255),
             static_cast<std::uint8_t>(mComponents[2].get() * 255),
             static_cast<std::uint8_t>(mComponents[3].get() * 255) };
#else
    return { static_cast<sf::Uint8>(RGBA_[0].get() * 255),
             static_cast<sf::Uint8>(RGBA_[1].get() * 255),
             static_cast<sf::Uint8>(RGBA_[2].get() * 255),
         static_cast<sf::Uint8>(RGBA_[3].get() * 255) };
#endif
}
