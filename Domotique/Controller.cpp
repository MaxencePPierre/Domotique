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
using namespace domotique::xml;

namespace domotique {
namespace actor {
std::shared_ptr< Controller > Controller::makeController(XMLNode * node)
{
	std::shared_ptr< Controller > controller;
	ElementType type = ElementTypeMap.at(
			node->ToElement()->FindAttribute(
					AttributeMap.at(Attributes::Type).c_str() )->Value() );
	switch(type)
	{
		case ElementType::OnOff:
			controller.reset( new OnOff( node ) );
			break;
		case ElementType::Proportional:
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
