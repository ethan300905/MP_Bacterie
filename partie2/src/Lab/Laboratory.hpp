#ifndef LABORATORY_HPP
#define LABORATORY_HPP
#include "Culturedish.hpp"

class Laboratory
{
public:
    Laboratory();
    Laboratory(const Laboratory&) = delete;
    Laboratory& operator=(const Laboratory&) = delete;
    void nextDish();
    void previousDish();
    size_t getCurrentDishId() const;
    void increaseTemperature();
    void decreaseTemperature();
    double getTemperature() const;
    void reset();
    void resetControls();

private:
    std::vector<CultureDish> CultureDishes_;
    size_t indice_;

};

#endif // LABORATORY_HPP
