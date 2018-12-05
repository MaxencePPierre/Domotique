/*
 * \file Controller.cpp
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#include "Controller.h"
#include "tinyxml2.h"
#include "OnOff.h"

using namespace tinyxml2;
using namespace domotique::actor::controller;

namespace domotique {
namespace actor {
std::shared_ptr< Controller > Controller::makeController(XMLNode * node)
{
	std::shared_ptr<Controller> controller;
	controller.reset(new OnOff(node));
	return controller;
}
}
}
