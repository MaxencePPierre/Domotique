/*
 * \file Controller.h
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Actor.h"

namespace domotique{ namespace actor {

class Controller: public Actor {
private:
	double _influence;
public:
	double Influence() const { return _influence; }
	Controller(double influence);
	virtual ~Controller();
};

}}

#endif /* CONTROLLER_H_ */
