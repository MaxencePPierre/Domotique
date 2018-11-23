/*
 * Random.cpp
 *
 *  Created on: 13 Nov 2018
 *      Author: pcoo34
 */
#include <vector>

// DEBUG ONLY TODO: REMOVE THIS
#include <iostream>

#include "Random.h"
#include "tinyxml2.h"
#include "XmlParse.h"

using namespace tinyxml2;
using namespace domotique::xml;

namespace domotique { namespace actor { namespace phenomenon {

void Random::Calculate()
{
	_value = _distribution(_generator);
}

Random::Random(tinyxml2::XMLNode * node)
{
	_valueLow = 1;
	_valueHigh = 10;
}

Random::Random(double valueLow, double valueHigh) : _valueLow(valueLow), _valueHigh(valueHigh) {
	_distribution = std::uniform_real_distribution<double>(_valueLow, _valueHigh);
}

Random::~Random() {
	// TODO Auto-generated destructor stub
}

}}}
