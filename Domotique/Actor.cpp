/*
 * Actor.cpp
 *
 *  Created on: 13 Nov 2018
 *      Author: pcoo34
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
		std::string elementName = child->Name();
//		std::map<const std::string, XMLMap::Element>::iterator pm = _requiredParams.find(elementName);

		std::set<XMLMap::Element>::iterator pm = _requiredParams.find(XMLMap::ElementMap[elementName]);
		if(_requiredParams.end() == pm)
		{
			pm = _optionalParams.find(XMLMap::ElementMap[elementName]);
			if(_optionalParams.end() == pm)
			{
				//parameter not in parameter list for this class
				std::stringstream s;
				s << "Parameter " << elementName << " not in parameter list";
				throw XMLParseException(s.str().c_str(), __FILE__, __LINE__);
			}
		}
		// check for multiple addition of parameters
		if(0 < _paramList.count(XMLMap::ElementMap[elementName]))
			throw XMLParseException("Parameter present multiple times",	__FILE__, __LINE__);

		const char * textValue = child->GetText();
		if(!textValue)
			throw XMLParseException("Parameter has no value", __FILE__, __LINE__);

		//TODO Generalise method below to include long integers
		double value = std::stod(textValue);
		// Add parameter to map
		_paramList.insert(std::pair<XMLMap::Element, double>(XMLMap::ElementMap[elementName], value));
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
