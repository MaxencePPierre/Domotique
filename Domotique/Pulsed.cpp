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
			Element::TRISE,
			Element::TFALL,
			Element::PWIDTH,
			Element::PERIOD
	};
	_optionalParams = {
			{Element::TDEL	, 0.0}
	};
	populate(node);
}

void Pulsed::Calculate(int tick){

	double intermediateValue;

	int tickModT = (tick + static_cast<int>(_paramList[Element::TDEL])) % static_cast<int>(_paramList[Element::PERIOD]);
	if(tick <= _paramList[Element::TDEL]) {
		intermediateValue = _paramList[Element::VLOW];
	}
	else if(tickModT <= _paramList[Element::TRISE]) {
		intermediateValue = (_paramList[Element::VHIGH] - _paramList[Element::VLOW]) * tickModT;
		if(intermediateValue > _paramList[Element::VHIGH]) {
			intermediateValue = _paramList[Element::VHIGH];
		}
	}
	else if((_paramList[Element::TRISE] < tickModT) && (
			tickModT <= _paramList[Element::TRISE] + _paramList[Element::PWIDTH])) {
		intermediateValue = _paramList[Element::VHIGH];
	}
	else if((_paramList[Element::TRISE] + _paramList[Element::PWIDTH] < tickModT) && (
			tickModT <= _paramList[Element::TRISE] + _paramList[Element::PWIDTH] + _paramList[Element::TFALL])) {
		intermediateValue = _paramList[Element::VHIGH] - (_paramList[Element::VHIGH] - _paramList[Element::VLOW]) * tickModT;
		if(intermediateValue < _paramList[Element::VLOW]) {
			intermediateValue = _paramList[Element::VLOW];
		}
	}
	else {
		intermediateValue = _paramList[Element::VLOW];
	}


	intermediateValue += BoxMuller(0,1);
	_value = intermediateValue;
}
}
}
}
