/**
 * \file Actor.h
 * \brief Actor class
 * \date 13 Nov 2018
 * \author pcoo34
 */

#ifndef ACTOR_H_
#define ACTOR_H_

#include <set>
#include "tinyxml2.h"

#include "XmlParse.h"

namespace domotique{ namespace actor {

/** \brief Base class for all actors in simulation
 *
 * An Actor here is defined as an entity taking an active part in the simulation.
 * This class serves as the base for all actors; that is to say all Phenomena, Controllers and States in the simulation */
class Actor {
protected:
	/// The value generated when Calculate() is called
	double _value = 0;
	/**
	 * \brief The set of parameters necessary for the class to function
	 *
	 * This is populated by the constructor of each class before the Actor::populate function is called to parse the xml
	 * */
	std::set<xml::XMLMap::Element> _requiredParams;
	/**
	 * \brief The set of parameters not strictly necessary for the class to function
	 *
	 * This is populated by the constructor of each class before the Actor::populate function is called to parse the xml
	 * */
	std::set<xml::XMLMap::Element> _optionalParams;
	/**
	 * \brief Collection of class' parameters
	 *
	 * This is a mapping of Element types to values.
	 * The required value is accessed by using the Element type as a key to the map.
	 * */
	std::map<xml::XMLMap::Element, double> _paramList;
public:
	/// Calculates a new value each timestep based on each actor subtype's internal rules
	virtual void Calculate() = 0;
	/// Accessor method for the actor's internal value
	double Value() const { return _value; };
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
	Actor();
	virtual ~Actor();
};

}}

#endif /* ACTOR_H_ */
