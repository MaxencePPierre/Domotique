/*
 * \file XMLParseable.cpp
 *
 * \date 26 nov. 2018
 * \author pcoo34
 */

#include "XMLParseable.h"

#include <vector>
#include <string>
#include <sstream>

#include <iostream>

using namespace tinyxml2;

namespace domotique {
namespace xml {

// TODO Generalise this to an XMLParseable class so Server, Runner and Actor can all use this
void XMLParseable::populate(XMLNode * node)
{
	// Read all children ( i.e. parameters ) into vector for later processing
	std::vector< XMLElement * > children;
	for( auto * child = node->FirstChildElement(); child; child = child->NextSiblingElement() )
		children.push_back( child );

	// Attempt to read parameters into _paramList, matched with their values
	for( auto * child : children )
	{
		XMLMap::Element element = XMLMap::ElementMap[child->Name()];
		auto reqParam = _requiredParams.find( element );
		if( _requiredParams.end() == reqParam )
		{
			auto optParam = _optionalParams.find( element );
			if( _optionalParams.end() == optParam )
			{
				//parameter not in parameter list for this class
				std::stringstream s;
				s << "Parameter " << child->Name() << " not in parameter list";
				throw XMLParseException( s.str().c_str(), __FILE__, __LINE__ );
			}
		}
		// check for multiple addition of parameters
		if( 0 < _paramList.count( element ) ) throw XMLParseException( "Parameter present multiple times", __FILE__, __LINE__ );

		//Attempt to get the text value of the parameter and store the parameter, value pair
		const char * textValue = child->GetText();
		if( !textValue )
		{
			if( _requiredParams.end() != reqParam )
			{	// If this is a required parameter, error
				throw XMLParseException( "Parameter has no value", __FILE__, __LINE__ );
			}
			// If this is an optional parameter, ignore; the parameter and default value will be added at the end anyways
		} else
		{
			//TODO Generalise method below to include long integers
			double value = std::stod( textValue );
			// Add parameter to map
			_paramList.insert( std::pair< XMLMap::Element, double >( element, value ) );
		}
	}

	// Ensure all required parameters have been read
	for( auto required : _requiredParams )
	{
		auto search = _paramList.find( required );
		if( _paramList.end() == search ) throw XMLParseException( "Required parameter not present", __FILE__, __LINE__ );
	}
	// Insert optional parameters with default values if not present
	for( auto optional : _optionalParams )
	{
		auto search = _paramList.find( optional.first );
		if( _paramList.end() == search ) _paramList.insert( optional );
	}
}

XMLParseable::XMLParseable()
{
	// TODO Auto-generated constructor stub

}

XMLParseable::~XMLParseable()
{
	// TODO Auto-generated destructor stub
}

} /* namespace xml */
} /* namespace domotique */
