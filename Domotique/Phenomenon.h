/*
 * \file Phenomenon.h
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#ifndef PHENOMENON_H_
#define PHENOMENON_H_

#include <cmath>
#include <memory>

#include <random>
#include "Actor.h"
#include "tinyxml2.h"

namespace domotique{ namespace actor {

const double pi = std::acos( -1 );

/**
 * \brief Specific methods and members needed for phenomena
 *
 * Entirely empty for phase one
 */
class Phenomenon: public Actor {
protected:
	static double BoxMuller(double mu, double sigma = standardDeviation);
public:
	static std::default_random_engine generator;
	static std::uniform_real_distribution<double> uniform;
	static constexpr double standardDeviation = 80.0;
	static std::shared_ptr<Phenomenon> makePhenomenon(tinyxml2::XMLNode * node);
};

}}
#endif /* PHENOMENON_H_ */
