/*
 * Threshold.cpp
 *
 *  Created on: 13 Nov 2018
 *      Author: pcoo34
 */
#include <map>
#include <string>
#include <vector>
#include "XmlParse.h"

#include "Threshold.h"

// TODO: remove this
#include <iostream>

using namespace domotique::xml;
using namespace tinyxml2;
namespace domotique{ namespace actor{ namespace controller {

void Threshold::Calculate()
{
	double phalue = _phenomenon->Value();
	_value = (phalue > _paramList[XMLMap::Element::Saturation]) ? _paramList[XMLMap::Element::Saturation] : phalue;
}

std::map<const std::string, xml::XMLMap::Element> Threshold::_requiredParams =
{
		{"saturation",	XMLMap::Element::Saturation}
};
std::map<const std::string, xml::XMLMap::Element> Threshold::_optionalParams =
{

};


Threshold::Threshold(tinyxml2::XMLNode * node, const Phenomenon* phenomenon): _phenomenon(phenomenon)
{
	std::vector<XMLNode *> params;
	XMLNode * param;
	for(param = node->FirstChild(); param; param = param->FirstChild())
		params.push_back(param);

	for(auto n = params.begin(); n != params.end() && NULL != (*n)->ToElement(); n++)
	{
		std::string elementName = (*n)->ToElement()->Name();
		std::map<const std::string, XMLMap::Element>::iterator pm = _requiredParams.find(elementName);
		if(_requiredParams.end() == pm)
		{
			pm = _optionalParams.find(elementName);
			if(_optionalParams.end() == pm)
			{
				//parameter not in parameter list for this class
				throw XMLParseException("Parameter not in parameter list",
						__FILE__, __LINE__);
			}
		}
		// check for multiple addition of parameters
		if(0 < _paramList.count(pm->second))
			throw XMLParseException("Parameter present multiple times",	__FILE__, __LINE__);

		const char * textValue = (*n)->ToElement()->GetText();
		if(!textValue)
			throw XMLParseException("Parameter has no value", __FILE__, __LINE__);
		double value = std::stod(textValue);
		// Add parameter to map
		_paramList.insert(std::pair<XMLMap::Element, double>(pm->second, value));
		std::cout << "Found parameter " << _paramList[pm->second] << ", " << value << std::endl;
	}
}

Threshold::Threshold(double saturation, const Phenomenon* phenomenon) : _phenomenon(phenomenon) {
	_paramList.insert(std::pair<XMLMap::Element, double>(XMLMap::Element::Saturation, saturation));
}

Threshold::~Threshold() {}

}}}
