/*
 * Random.cpp
 *
 *  Created on: 13 Nov 2018
 *      Author: pcoo34
 */

#include "Random.h"

namespace domotique { namespace actor { namespace phenomenon {

void Random::Calculate()
{
	_value = _distribution(_generator);
}

Random::Random(double influence, double valueLow, double valueHigh) : Phenomenon(influence), _valueLow(valueLow), _valueHigh(valueHigh) {
	_distribution = std::uniform_real_distribution<double>(_valueLow, _valueHigh);
}

Random::~Random() {
	// TODO Auto-generated destructor stub
}

}}}
