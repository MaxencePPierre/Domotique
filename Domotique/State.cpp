/*
 * State.cpp
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#include "State.h"

namespace domotique{ namespace actor {

State::State(Phenomenon& phenomenon, Controller& controller)
: _phenomenon(phenomenon), _controller(controller) {
	// TODO Auto-generated constructor stub
}

State::~State() {
	// TODO Auto-generated destructor stub
}

}}
