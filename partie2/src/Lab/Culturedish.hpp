#ifndef CULTUREDISH_HPP
#define CULTUREDISH_HPP
#include "Bacterium.hpp"
#include "Nutrient.hpp"
#include <vector>

class CultureDish
{
public:
    CultureDish();

private:
    vector<Bacterium> Bacteriums_;
    vector<Nutrient> Nutrientsource_;
    double temperature_;
}
};

#endif // CULTUREDISH_HPP
