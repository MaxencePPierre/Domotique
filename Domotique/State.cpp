/*
 * State.cpp
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#include "State.h"
#include "Phenomenon.h"
#include "Controller.h"

namespace domotique{ namespace actor {

void State::Calculate()
{
	double oldvalue = _value;
	_value = oldvalue
			+ ((_phenomenon.Value() - oldvalue) * _phenomenon.Influence())
			+ ((_controller.Value() - oldvalue) * _controller.Influence());
}

State::State(const Phenomenon& phenomenon, const Controller& controller)
: _phenomenon(phenomenon), _controller(controller) {
	// TODO Auto-generated constructor stub
}

State::~State() {
	// TODO Auto-generated destructor stub
}

}}
