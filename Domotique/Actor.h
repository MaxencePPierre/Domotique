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
	std::set<xml::XMLMap::Element> _requiredParams;
	std::set<xml::XMLMap::Element> _optionalParams;
	std::map<xml::XMLMap::Element, double> _paramList;
public:
	/// Calculates a new value each timestep based on each actor subtype's internal rules
	virtual void Calculate() = 0;
	/// Accessor method for the actor's internal value
	double Value() const { return _value; };
	void populate(tinyxml2::XMLNode* node);
	Actor();
	virtual ~Actor();
};

}}

#endif /* ACTOR_H_ */
