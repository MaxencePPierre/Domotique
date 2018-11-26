/*
 * Phenomenon.h
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#ifndef PHENOMENON_H_
#define PHENOMENON_H_

#include "Actor.h"
#include "tinyxml2.h"

namespace domotique{ namespace actor {

class Phenomenon: public Actor {
protected:
	double BoxMuller(double mu, double sigma);
public:
	Phenomenon(tinyxml2::XMLNode *);
	Phenomenon();
	virtual ~Phenomenon();
};

}}
#endif /* PHENOMENON_H_ */
