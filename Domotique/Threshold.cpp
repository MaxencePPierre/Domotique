/*
 * Threshold.cpp
 *
 *  Created on: 13 Nov 2018
 *      Author: pcoo34
 */

#include "Threshold.h"

namespace domotique{ namespace actor{ namespace controller {

void Threshold::Calculate()
{
	double phalue = _phenomenon.Value();
	_value = (phalue > _saturation) ? _saturation : phalue;
}

Threshold::Threshold(double influence, double saturation, Phenomenon& phenomenon)
: Controller(influence), _saturation(saturation), _phenomenon(phenomenon) {}

Threshold::~Threshold() {}

}}}
