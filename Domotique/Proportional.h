/*
 * \file Proportional.h
 *
 * \date 5 déc. 2018
 * \author pcoo34
 */

#ifndef PROPORTIONAL_H_
#define PROPORTIONAL_H_

#include "Controller.h"
#include "tinyxml2.h"

namespace domotique {
namespace actor {
namespace controller {

class Proportional: public Controller
{
	public:
		void Calculate();
		Proportional(tinyxml2::XMLNode * node);
};

}
}
}

#endif /* PROPORTIONAL_H_ */
