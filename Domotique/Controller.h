/*
 * \file Controller.h
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Actor.h"
#include "tinyxml2.h"

namespace domotique{ namespace actor {

class Controller: public Actor {
public:
	Controller(tinyxml2::XMLNode * node);
	Controller();
	virtual ~Controller();
};

}}

#endif /* CONTROLLER_H_ */
