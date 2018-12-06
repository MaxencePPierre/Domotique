/**
 * \file Actor.h
 * \brief Actor class
 * \date 13 Nov 2018
 * \author pcoo34
 */

#ifndef ACTOR_H_
#define ACTOR_H_

#include <set>
#include <memory>
#include "tinyxml2.h"

#include "XMLParseable.h"

namespace domotique{ namespace actor {

/** \brief Base class for all actors in simulation
 *
 * An Actor here is defined as an entity taking an active part in the simulation.
 * This class serves as the base for all actors; that is to say all Phenomena, Controllers and States in the simulation.
 * It derives from XMLParseable in order that the leaf classes might use XMLParseable's xml parsing methods to get their parameters from an xml file.
 * */
class Actor : public xml::XMLParseable {
protected:
	/// The value generated when Calculate() is called
	double _value = 0;
public:
	/* \brief Calculates a new value each timestep based on each actor subtype's internal rules
	 * Passes tick to those actors that need it.
	 * Overridden by leaf classes.
	 * \param tick Current simulation tick.
	 */
	virtual void Calculate(int tick) = 0;
	/// Accessor method for the actor's internal value
	double Value() const { return _value; };
	std::string Name() {return _attributeList[xml::XMLMap::Attributes::Name];}
	Actor(){_requiredAttributes = {xml::XMLMap::Attributes::Name, xml::XMLMap::Attributes::Type};};
};
}}

#endif /* ACTOR_H_ */
