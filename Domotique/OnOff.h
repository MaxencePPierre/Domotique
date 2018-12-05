/*
 * \file OnOff.h
 *
 * \date 3 déc. 2018
 * \author pcoo34
 */

#ifndef ONOFF_H_
#define ONOFF_H_

#include "Controller.h"
#include "tinyxml2.h"

namespace domotique {namespace actor {namespace controller {

class OnOff: public Controller {
public:
	void Calculate();
	OnOff(tinyxml2::XMLNode * node);
};

}}}

#endif /* ONOFF_H_ */
