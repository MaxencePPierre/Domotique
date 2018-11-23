/*
 * State.cpp
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#include "State.h"
#include "Phenomenon.h"
#include "Controller.h"

#include "tinyxml2.h"

namespace domotique{ namespace actor {

void State::Calculate()
{
	double oldvalue = _value;
	_value = oldvalue
			+ ((_phenomenon->Value() - oldvalue) * _influencePhenomenon)
			+ ((_controller->Value() - oldvalue) * _influenceController);
}

State::State(const Phenomenon* phenomenon, const Controller* controller, tinyxml2::XMLNode * node) : _phenomenon(phenomenon), _controller(controller)
{
	_influencePhenomenon = 0.1;
	_influenceController = 0.5;
}

State::~State() {
	// TODO Auto-generated destructor stub
}

}}
