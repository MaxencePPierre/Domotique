/*
 * \file Threshold.cpp
 *
 * \date 13 Nov 2018
 * \author pcoo34
 */
#include <map>
#include <string>
#include <vector>
#include "XmlParse.h"

#include "Threshold.h"

using namespace domotique::xml;
using namespace tinyxml2;
namespace domotique{ namespace actor{ namespace controller {

void Threshold::Calculate()
{
	double phalue = _phenomenon->Value();
	_value = (phalue > _paramList[XMLMap::Element::Saturation]) ? _paramList[XMLMap::Element::Saturation] : phalue;
}

Threshold::Threshold(tinyxml2::XMLNode * node, std::shared_ptr<Phenomenon> phenomenon): _phenomenon(phenomenon)
{
	_requiredParams = {
			{XMLMap::Element::Saturation}
	};
	_optionalParams = {};
	populate(node);
}

Threshold::Threshold(Threshold* t)
{
		this->_phenomenon = t->_phenomenon;
		this->_paramList = t->_paramList;
		this->_value = t->_value;
}
Threshold::~Threshold() {}

}}}
