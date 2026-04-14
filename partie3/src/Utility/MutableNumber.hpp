#pragma once
#ifndef MUTABLENUMBER_HPP
#define MUTABLENUMBER_HPP
#include <Random/Random.hpp>

class MutableNumber
{
public:
    MutableNumber(double, double, double, double, double, bool, bool);
    MutableNumber(j::Value const&);
    double getValue() const;
    void setValue(double);
    void mutate();

private:

    double clamp(double) const;

    double value_;
    double mutationProba_;
    bool isMax_;
    bool isMin_;
    double max_;
    double min_;
    double standardDeviation_;
};

#endif // MUTABLENUMBER_HPP
