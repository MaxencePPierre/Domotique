/*
 * \file Proportional.cpp
 *
 * \date 5 déc. 2018
 * \author pcoo34
 */

#include "Proportional.h"
#include "XMLMappings.h"

using namespace tinyxml2;
using namespace domotique::xml;
namespace domotique {
namespace actor {
namespace controller {

void Proportional::Calculate()
{

}

Proportional::Proportional(XMLNode * node)
{
	_requiredParams =
	{
			XMLMap::Element::SETPT
	};
}
}
}
}
