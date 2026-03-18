/*
 * POOSV 2026
 * Marco Antognini & Jamila Sam
 */

#pragma once

#include <string>

// Numerical constants
double const DEG_TO_RAD = 0.0174532925; ///< Degree to Radian conversion constant
double const TAU = 6.283185307;         ///< TAU constant (= 2 * PI)
double const PI = 3.141592654;          ///< PI constant
double const EPSILON = 1e-8;            ///< a small epsilon value

// Stats titles
namespace s
{

std::string const GENERAL = "general";
std::string const MONOTRICHOUS_BACTERIA = "monotrichous";
std::string const PILUS_MEDIATED_BACTERIA = "pilus mediated";
std::string const GROUP_MOTILITY_BACTERIA = "group motility";
std::string const BACTERIA = "bacteria";
std::string const SPEED = "speed";
std::string const BETTER = "tumble better prob";
std::string const WORSE = "tumble worse prob";
std::string const NUTRIENT_QUANTITY = "nutrient quantity";
std::string const NUTRIENT_SOURCES = "nutrient sources";
std::string const TENTACLE_LENGTH = "tentacle length";
std::string const TENTACLE_SPEED = "tentacle speed";
std::string const DISH_TEMPERATURE = "temperature";

} // s

