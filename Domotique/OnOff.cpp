/*
 * OnOff.cpp
 *
 *  Created on: 3 déc. 2018
 *      Author: pcoo34
 */

#include "OnOff.h"
#include "XMLMappings.h"
#include "State.h"

using namespace tinyxml2;
using namespace domotique::xml;

namespace domotique {namespace actor {namespace controller {

void OnOff::Calculate(int tick)
{
	double stateVal = _state->Value();
	if(stateVal > _paramList[XMLMap::Element::VTHRMAX])
		_value = _paramList[XMLMap::Element::VCTRLMIN];
	else if(stateVal > _paramList[XMLMap::Element::VTHRMIN])
		_value = _paramList[XMLMap::Element::VCTRLMAX];
	else
		_value = stateVal;
}

OnOff::OnOff(XMLNode * node) {
	_requiredParams = {
			XMLMap::Element::VTHRMAX,
			XMLMap::Element::VTHRMIN,
			XMLMap::Element::VCTRLMAX,
			XMLMap::Element::VCTRLMIN
	};
	_optionalParams = {};
	populate(node);
}

}}}
