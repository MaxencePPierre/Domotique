/*
 * Phenomenon.h
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#ifndef PHENOMENON_H_
#define PHENOMENON_H_

#include "Actor.h"

namespace domotique {
namespace process {

class Phenomenon: public Actor {
private:
	double _influence;
protected:
	double BoxMuller(double mu, double sigma);
public:
	double Influence();
	Phenomenon(double influence);
	virtual ~Phenomenon();
};

} /* namespace process */
} /* namespace domotique */

#endif /* PHENOMENON_H_ */
