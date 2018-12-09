/*
 * \file XMLParseable.h
 *
 * \date 26 nov. 2018
 * \author pcoo34
 */

#ifndef XMLPARSEABLE_H_
#define XMLPARSEABLE_H_

#include <set>

#include "tinyxml2.h"
#include "XMLMappings.h"

namespace domotique {
namespace xml {

/**
 * \brief Class with a utility method and member variables to enable xml parsing to be done generically
 *
 * Method to parse xml:
 * 	- declare set of required and optional parameters for the class
 * 	- call \c populate with XMLNode parameter passed to constructor
 * 	\note populate must be a separate function as the superclass' (this class') constructor is called before those of any children
 * */
class XMLParseable {
protected:
	/**
	 * \brief The set of parameters necessary for the class to function
	 *
	 * This is populated by the constructor of each class before the Actor::populate function is called to parse the xml
	 * */
	std::set<xml::Element> _requiredParams;
	/**
	 * \brief The set of parameters not strictly necessary for the class to function
	 *
	 * This is populated by the constructor of each class before the Actor::populate function is called to parse the xml
	 * \note No method of assigning default values to optional parameters has yet been implemented. Possibly using a map ( similar to \c _paramList ).
	 * */
	std::map<xml::Element, double> _optionalParams;
	/**
	 * \brief Collection of class' parameters
	 *
	 * This is a mapping of Element types to values.
	 * The required value is accessed by using the Element type as a key to the map.
	 * */
	std::map<xml::Element, double> _paramList;
	std::set<xml::Attributes> _requiredAttributes;
	std::map<xml::Attributes, std::string> _attributeList;
public:
	XMLParseable();
	virtual ~XMLParseable();
	/**
	 * \brief Takes \c node and extracts the parameters in \c _requiredParams and \c _optionalParams from its children.
	 *
	 * \param node Pointer to the XMLNode that is the root of the parameter tree.
	 *
	 * Attempts to match each child of \c node with a parameter in the set \f$\{\_requiredParams \cup \_optionalParams\}\f$.
	 *
	 * \throws XMLParseException
	 * 		- Parameter is not in either the required or optional list
	 * 		- Parameter has already been added to the parameter list ( i.e. the parameter is defined multiple times )
	 * 		- Parameter is empty ( has no value )
	 * 		- Parameter which is in the required list was not found as a child of \c node
	 * */
	void populate(tinyxml2::XMLNode* node);
};

} /* namespace xml */
} /* namespace domotique */

#endif /* XMLPARSEABLE_H_ */
