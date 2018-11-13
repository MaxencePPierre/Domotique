/*
 * Threshold.h
 *
 *  Created on: 13 Nov 2018
 *      Author: pcoo34
 */

#ifndef THRESHOLD_H_
#define THRESHOLD_H_

#include "Controller.h"

namespace domotique{ namespace actor{ namespace controller {

class Threshold: public Controller {
private:
	double _saturation;
public:
	Threshold(double influence, double saturation);
	virtual ~Threshold();
};

}}}

#endif /* THRESHOLD_H_ */
