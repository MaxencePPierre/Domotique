/*
 * Threshold.cpp
 *
 *  Created on: 13 Nov 2018
 *      Author: pcoo34
 */

#include "Threshold.h"

namespace domotique{ namespace actor{ namespace controller {

Threshold::Threshold(double influence, double saturation) : Controller(influence), _saturation(saturation) {
	// TODO Auto-generated constructor stub

}

Threshold::~Threshold() {
	// TODO Auto-generated destructor stub
}

}}}
