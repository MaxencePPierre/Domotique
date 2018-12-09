/*
 * \file State.cpp
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#include "State.h"
#include "Phenomenon.h"
#include "Controller.h"
#include <iostream>
#include "tinyxml2.h"

#include "XMLMappings.h"

namespace domotique{ namespace actor {

void State::Calculate(int tick)
{
	double oldvalue = _value;
	_value = oldvalue
			+ ((_phenomenon->Value() - oldvalue) * _paramList[xml::Element::InfluencePhenomenon])
			+ ((_controller->Value() - oldvalue) * _paramList[xml::Element::InfluenceController]);
}

State::State(std::shared_ptr<Phenomenon> phenomenon, std::shared_ptr<Controller> controller, tinyxml2::XMLNode * node)
: _phenomenon(phenomenon), _controller(controller)
{
	_requiredParams =
	{
			{xml::Element::InfluencePhenomenon},
			{xml::Element::InfluenceController}
	};
	_optionalParams =
	{

	};
	populate(node);
}

State::~State() {
	// TODO Auto-generated destructor stub
}

}}
