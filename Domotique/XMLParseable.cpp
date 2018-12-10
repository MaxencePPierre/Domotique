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

void XMLParseable::populate(XMLNode * node)
{
	for( auto attribute : _requiredAttributes)
	{
		XMLElement * element = node->ToElement();
		if(!element)
		{
			std::stringstream s;
			s << "Failed to convert " << node->Value() << " node to an element";
			throw XMLParseException(s.str().c_str(), __FILE__, __LINE__);
		}
		const XMLAttribute * xmlAttribute = element->FindAttribute( AttributeMap.at(attribute).c_str() );
		if(!xmlAttribute)
		{
			std::stringstream s;
			s << "Attribute " << AttributeMap.at(attribute) << " from required attributes list not found in " << node->Value() << " element";
			throw XMLParseException(s.str().c_str(), __FILE__, __LINE__);
		}
		std::string value = xmlAttribute->Value();
		if( value.empty())
		{
			std::stringstream s;
			s << "Attribute " << AttributeMap.at(attribute) << " does not have a value in " << node->Value() << " element";
			throw XMLParseException(s.str().c_str(), __FILE__, __LINE__);
		}
		_attributeList.insert(std::pair< Attributes, std::string>( attribute, value) );
	}

	// Read all children ( i.e. parameters ) into vector for later processing
	std::vector< XMLElement * > children;
	for( auto * child = node->FirstChildElement(); child; child = child->NextSiblingElement() )
		children.push_back( child );

	// Attempt to read parameters into _paramList, matched with their values
	for( auto * child : children )
	{
		Element element = ElementMap.at(child->Name());
		auto reqParam = _requiredParams.find( element );
		if( _requiredParams.end() == reqParam )
		{
			auto optParam = _optionalParams.find( element );
			if( _optionalParams.end() == optParam )
			{
				//parameter not in parameter list for this class
				std::stringstream s;
				s << "Parameter " << child->Name() << " read from config file is neither an optional nor required parameter for the "
						<< node->ToElement()->FindAttribute( AttributeMap.at(Attributes::Type).c_str() )->Value() << " actor";
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
			try{
				double value;
				value = std::stod( textValue );
				_paramList.insert( std::pair< Element, double >( element, value ) );
			} catch (std::invalid_argument& e) {
				std::cout << textValue << " could not be converted to a double\n";
			}
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
} /* namespace xml */
} /* namespace domotique */
