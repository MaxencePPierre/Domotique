/*
 * \file Proportional.cpp
 *
 * \date 5 déc. 2018
 * \author pcoo34
 */

#include "Proportional.h"

#include <initializer_list>
#include <map>
#include <set>

#include "Actor.h"
#include "State.h"
#include "XMLMappings.h"

using namespace tinyxml2;
using namespace domotique::xml;

namespace domotique {namespace actor {namespace controller {

void Proportional::Calculate(int tick)
{
	double stateVal = _state->Value();
	double error = stateVal - _paramList[Element::SETPT];
	_value = stateVal - (_paramList[Element::GAIN] * error);
}

Proportional::Proportional(XMLNode * node)
{
	_requiredParams =
	{
			Element::SETPT
	};
	_optionalParams =
	{
			{ Element::GAIN	, 1.0 }
	};
	populate(node);
}

}}}
