#include "MutableNumber.hpp"

MutableNumber::MutableNumber(double value, double mutationProba, double standardDeviation, bool isMax = false, bool isMin = false, double max = 0, double min = 0)
    :
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
    :     mutationProba_ (config["rate"].toDouble()),
      standardDeviation_ (config["sigma"].toDouble()),
      isMax_ (config["clamp max"].toDouble()),
      isMin_  (config["clamp min"].toDouble()),
      max_ (config["max"].toDouble()),
      min_  (config["min"].toDouble())
{
    setValue(config["initial"].toDouble());
    if(max_<min_){
        throw std::invalid_argument("La valeur min est supérieure à la valeur max");    // on vérifie le cas limite
    }
}

double MutableNumber::getValue() const {

    return value_;
}

void MutableNumber::setValue(double value){
    value_ = clamp(value);
}

void MutableNumber::mutate(){
    if(bernoulli(mutationProba_) == 1){
        setValue(normal(0,standardDeviation_ * standardDeviation_));
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

MutableNumber probability(double initialValue , double mutationProbability, double sigma){
    return MutableNumber(initialValue, mutationProbability, sigma, true, true, 1,0);
}
MutableNumber probability(j::Value const& config){
    return probability(config["initial"].toDouble(),config["rate"].toDouble(), config["sigma"].toDouble());
}
MutableNumber positive(double initialValue, double mutationProbability, double sigma, bool isMax = false, double max = 0){
    return MutableNumber(initialValue, mutationProbability, sigma, isMax, true , max, 0);
}
MutableNumber positive(j::Value const& config, bool isMax = false, double max = 0){
    return positive(config["initial"].toDouble(),config["rate"].toDouble(), config["sigma"].toDouble());
}







