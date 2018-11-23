/*
 * \file Actor.cpp
 *
 * \date 13 Nov 2018
 * \author pcoo34
 */
#include <sstream>
#include <map>
#include <string>
#include <vector>

#include "Actor.h"

using namespace tinyxml2;
using namespace domotique::xml;

namespace domotique{ namespace actor {

void Actor::populate(XMLNode * node) {
	// Read all children ( i.e. parameters ) into vector for later processing
	std::vector<XMLElement *> children;
	for(auto * child = node->FirstChildElement(); child; child = child->NextSiblingElement())
		children.push_back(child);

	// Attempt to read parameters into _paramList, matched with their values
	for(auto * child : children)
	{
		XMLMap::Element element = XMLMap::ElementMap[child->Name()];
		std::set<XMLMap::Element>::iterator pm = _requiredParams.find(element);
		if(_requiredParams.end() == pm)
		{
			pm = _optionalParams.find(element);
			if(_optionalParams.end() == pm)
			{
				//parameter not in parameter list for this class
				std::stringstream s;
				s << "Parameter " << child->Name() << " not in parameter list";
				throw XMLParseException(s.str().c_str(), __FILE__, __LINE__);
			}
		}
		// check for multiple addition of parameters
		if(0 < _paramList.count(element))
			throw XMLParseException("Parameter present multiple times",	__FILE__, __LINE__);

		const char * textValue = child->GetText();
		if(!textValue)
			throw XMLParseException("Parameter has no value", __FILE__, __LINE__);

		//TODO Generalise method below to include long integers
		double value = std::stod(textValue);
		// Add parameter to map
		_paramList.insert(std::pair<XMLMap::Element, double>(element, value));
	}

	// Ensure all required parameters have been read
	for(auto required : _requiredParams)
	{
		auto search = _paramList.find(required);
		if(_paramList.end() == search)
			throw XMLParseException("Required parameter not present", __FILE__, __LINE__);
	}
}

Actor::Actor(){}

Actor::~Actor() {
	// TODO Auto-generated destructor stub
}


}}
