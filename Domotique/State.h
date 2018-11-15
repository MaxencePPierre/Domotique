/*
 * State.h
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#ifndef STATE_H_
#define STATE_H_

#include "Actor.h"

#include "Phenomenon.h"
#include "Controller.h"

namespace domotique{ namespace actor {
class State: public Actor {
private:
	Phenomenon& _phenomenon;
	Controller& _controller;
public:
	void Calculate();

	State(Phenomenon& phenomenon, Controller& controller);
	virtual ~State();
};

}}

#endif /* STATE_H_ */
