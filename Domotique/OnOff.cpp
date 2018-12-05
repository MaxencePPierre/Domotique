/*
 * OnOff.cpp
 *
 *  Created on: 3 déc. 2018
 *      Author: pcoo34
 */

#include "OnOff.h"
#include "XMLMappings.h"

using namespace tinyxml2;
using namespace domotique::xml;

namespace domotique {namespace actor {namespace controller {

void OnOff::Calculate()
{
	_value = 0;
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
