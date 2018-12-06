/*
 * \file Controller.cpp
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#include "Controller.h"

#include <map>
#include <string>

#include "OnOff.h"
#include "Proportional.h"
#include "XMLMappings.h"

using namespace tinyxml2;
using namespace domotique::actor::controller;
using domotique::xml::XMLMap;

namespace domotique {
namespace actor {
std::shared_ptr< Controller > Controller::makeController(XMLNode * node)
{
	std::shared_ptr< Controller > controller;
	XMLMap::ElementType type = XMLMap::ElementTypeMap.at(
			node->ToElement()->FindAttribute(
					XMLMap::AttributeMap[XMLMap::Attributes::Type].c_str() )->Value() );
	switch(type)
	{
		case XMLMap::ElementType::OnOff:
			controller.reset( new OnOff( node ) );
			break;
		case XMLMap::ElementType::Proportional:
			controller.reset( new Proportional( node ) );
			break;
		default:
			throw xml::XMLParseException("Type of controller not recognised", __FILE__, __LINE__);
			break;
	}
	return controller;
}
}
}
