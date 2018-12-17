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
	double T = _paramList[Element::PERIOD];
	double t=0;
	double intermediateValue;
	while(t<T){
		if(t < _paramList[Element::TDEL] + _paramList[Element::TRISE]) {
			intermediateValue = (_paramList[Element::VHIGH] - _paramList[Element::VLOW]) * t;
		}
		else if(_paramList[Element::TDEL] + _paramList[Element::TRISE] < t < _paramList[Element::PWIDTH]) {
			intermediateValue = _paramList[Element::VHIGH];
		}
		else if(_paramList[Element::TDEL] + _paramList[Element::TRISE] + _paramList[Element::PWIDTH] < t < _paramList[Element::TDEL] + _paramList[Element::TRISE] + _paramList[Element::PWIDTH] + _paramList[Element::TRISE] + _paramList[Element::TFALL]) {
			intermediateValue = intermediateValue - (_paramList[Element::VHIGH] - _paramList[Element::VLOW]) * t;
		}
		else if(_paramList[Element::TDEL] + _paramList[Element::TRISE] + _paramList[Element::PWIDTH] + _paramList[Element::TFALL] < t < _paramList[Element::PERIOD]) {
			intermediateValue = _paramList[Element::VLOW];
		}
		t++;
	}
	intermediateValue += BoxMuller(0,1);
}


}

}
}
