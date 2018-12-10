/*
 * \file Pulsed.cpp
 *
 * \date 10 Dec 2018
 * \author pcoo34
 */

#include "Pulsed.h"
#include "XMLMappings.h"

using namespace tinyxml2;
using namespace domotique::xml;

namespace domotique {
namespace actor {
namespace phenomenon {

Pulsed::Pulsed(XMLNode* node)
{
	_requiredParams = {
			Element::VLOW,
			Element::VHIGH,
			Element::TDEL,
			Element::TFALL,
			Element::PWIDTH,
			Element::PERIOD
	};
	_optionalParams = {
			Element::TRISE
	};
	populate(node);
}

void Pulsed::Calculate(int tick){

}

}
}
}
