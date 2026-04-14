#include "MutableNumber.hpp"

MutableNumber::MutableNumber(double value, double mutationProba, double standardDeviation, double max = 0, double min = 0, bool isMax = false, bool isMin = false)
    : mutationProba_(mutationProba),
      standardDeviation_(standardDeviation)
{
    if(max_<min_){
        throw ("La valeur min est supérieure à la valeur max");   // on vérifie le cas limie
    }
    setValue(value);
}

MutableNumber::MutableNumber(j::Value const& config){  // Surcharge de constructeurs
    setValue(config["initial"].toDouble());
    mutationProba_ = config["rate"].toDouble();
    standardDeviation_ = config["sigma"].toDouble();
    isMax_ = config["clamp max"].toDouble();
    isMin_  = config["clamp min"].toDouble();
    max_ = config["max"].toDouble();
    min_  = config["min"].toDouble();
    if(max_<min_){
        throw ("La valeur min est supérieure à la valeur max");    // on vérifie le cas limie
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

