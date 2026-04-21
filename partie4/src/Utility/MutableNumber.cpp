#include "MutableNumber.hpp"

MutableNumber::MutableNumber(double value, double mutationProba, double standardDeviation, bool isMin, double min, bool isMax, double max)
    : //value_(0.0),
      mutationProba_(mutationProba),
      standardDeviation_(standardDeviation),
      isMax_(isMax),
      isMin_(isMin),
      max_(max),
      min_(min)
{
    if(max_<min_){
        throw std::invalid_argument("La valeur min est supérieure à la valeur max");   // on vérifie le cas limite
    }
    setValue(value);
}

MutableNumber::MutableNumber(j::Value const& config)  // Surcharge de constructeurs
    : mutationProba_ (config["rate"].toDouble()),
      standardDeviation_ (config["sigma"].toDouble()),
      isMax_ (config["clamp max"].toBool()), // toBool et pas toDouble?
      isMin_  (config["clamp min"].toBool()), // toBool et pas toDouble?
      max_ (config["max"].toDouble()),
      min_  (config["min"].toDouble())
{
    setValue(config["initial"].toDouble());
    if(max_<min_)
    {
        throw std::invalid_argument("La valeur min est supérieure à la valeur max");    // on vérifie le cas limite
    }
}

double MutableNumber::get() const {

    return value_;
}

void MutableNumber::setValue(double value){
    value_ = clamp(value);
}

void MutableNumber::mutate(){
    if(bernoulli(mutationProba_) == 1){
        double deviation = normal(0,standardDeviation_ * standardDeviation_);
        setValue(value_ + deviation);
    }
}

double MutableNumber::clamp(double value) const{  // sert à adapter la valeur si elle dépasse les bornes
    if(isMax_){
        if(value>max_){
            return max_;
        }
    }
    if(isMin_){
         if (value<min_){
             return min_;
         }
    }
    return value;
}

  // UTILISER Static???

MutableNumber MutableNumber::probability(double initialValue , double mutationProbability, double sigma){
    return MutableNumber(initialValue, mutationProbability, sigma, true , 0.0, true, 1.0);
}
MutableNumber MutableNumber::probability(j::Value const& config){
    return probability(config["initial"].toDouble(),config["rate"].toDouble(), config["sigma"].toDouble());
}
MutableNumber MutableNumber::positive(double initialValue, double mutationProbability, double sigma, bool isMax, double max){
    return MutableNumber(initialValue, mutationProbability, sigma, true, 0. , isMax, max);
}
MutableNumber MutableNumber::positive(j::Value const& config, bool isMax, double max){
    double initial = config["initial"].toDouble();
    double rate    = config["rate"].toDouble();
    double sigma   = config["sigma"].toDouble();

    return MutableNumber::positive(initial, rate, sigma, isMax, max);}
//                                                                                                        ^     ^ fallait les donner en param.






