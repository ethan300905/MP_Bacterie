/*
 * POOSV 2036
 * Marco Antognini & Jamila Sam
 */

#pragma once

#include <random>

/**
 *  @brief  Get a unique random number generator
 *
 *  @return always the same generator
 */
std::mt19937& getRandomGenerator();

