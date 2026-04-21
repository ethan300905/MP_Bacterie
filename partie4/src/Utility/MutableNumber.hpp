#pragma once

#include <Random/Random.hpp>

class MutableNumber
{
public:
    MutableNumber(double value, double mutationProba, double standardDeviation, bool isMax = false, double max=0.0, bool isMin=false, double min=0.0);
    MutableNumber(j::Value const&);
    MutableNumber() = default;
    double get() const;
    void setValue(double);
    void mutate();
    static MutableNumber probability(double , double , double);
    static MutableNumber probability(j::Value const&);
    static MutableNumber positive(double, double, double, bool isMax = false, double max = 0.0);
    static MutableNumber positive(j::Value const&, bool isMax = false, double max=0.0);

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


