/*
 * Controller.h
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Actor.h"

namespace domotique {
namespace process {

class Controller: public Actor {
private:
	double _influence;
public:
	double Influence();
	Controller();
	virtual ~Controller();
};

} /* namespace process */
} /* namespace domotique */

#endif /* CONTROLLER_H_ */
