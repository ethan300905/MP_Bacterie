#pragma once
#ifndef MUTABLENUMBER_HPP
#define MUTABLENUMBER_HPP
#include <Random/Random.hpp>

class MutableNumber
{
public:
    MutableNumber(double, double, double, bool, bool, double, double);
    MutableNumber(j::Value const&);
    double getValue() const;
    void setValue(double);
    void mutate();
    MutableNumber probability(double , double , double);
    MutableNumber probability(j::Value const&);
    MutableNumber positive(double , double , double, bool , double );
    MutableNumber positive(j::Value const&, bool, double);

private:

    double clamp(double) const;

    double value_;
    double mutationProba_;
    double standardDeviation_;
    bool isMax_;
    bool isMin_;
    double max_;
    double min_;

};

#endif // MUTABLENUMBER_HPP
