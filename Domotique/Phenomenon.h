/*
 * \file Phenomenon.h
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#ifndef PHENOMENON_H_
#define PHENOMENON_H_

#include "Actor.h"
#include "tinyxml2.h"
#include <memory>

namespace domotique{ namespace actor {

/**
 * \brief Specific methods and members needed for phenomena
 *
 * Entirely empty for phase one
 */
class Phenomenon: public Actor {
protected:
	double BoxMuller(double mu, double sigma);

public:
	static std::shared_ptr<Phenomenon> makePhenomenon(tinyxml2::XMLNode * node);
};

}}
#endif /* PHENOMENON_H_ */
