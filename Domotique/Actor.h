/**
 * \file Actor.h
 * \brief Actor class
 * \date 13 Nov 2018
 * \author pcoo34
 */

#ifndef ACTOR_H_
#define ACTOR_H_

namespace domotique{ namespace actor {

/** \brief Base class for all actors in simulation
 *
 * An Actor here is defined as an entity taking an active part in the simulation.
 * This class serves as the base for all actors; that is to say all Phenomena, Controllers and States in the simulation */
class Actor {
protected:
/// The value generated when Calculate() is called
	double _value = 0;
public:
	/// Calculates a new value each timestep based on each actor subtype's internal rules
	virtual void Calculate() = 0;
	/// Accessor method for the actor's internal value
	double Value() { return _value; };
	Actor();
	virtual ~Actor();
};

}}

#endif /* ACTOR_H_ */
