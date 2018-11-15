/*
 * \file State.h
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#ifndef STATE_H_
#define STATE_H_

#include "Actor.h"

#include "Phenomenon.h"
#include "Controller.h"

namespace domotique{ namespace actor {
/**
 * \brief The state upon which the Phenomenon and Controller act
 */
class State: public Actor {
	//TODO: Add a longer description
private:
	const Phenomenon& _phenomenon;
	const Controller& _controller;
public:
	/** Calculates the State's value for the current tick based on this formula:
	 * \f{align*}{
	 * 		v_t = v_{t-1}
	 * 			+ \left( v_{p_t} - v_{t-1} \right) \times I_p
	 * 			+ \left( v_{c_t} - v_{t-1} \right) \times I_c
	 *
	 * \f}
	 * where
	 * 	- \f$v_t,\,v_{t-1}\f$ : values of State at ticks \f$t\f$ and \f$t-1\f$
	 * 	- \f$v_{p_t},\,v_{c_t}\f$ : values of associated Phenomenon and Controller at tick \f$t\f$
	 * 	- \f$I_p,\,I_c\f$ : influences of associated Phenomenon and Controller
	 */
	void Calculate();

	/**
	 * \param phenomenon Phenomenon that will act on the State; reference stored in \c _phenomenon.
	 * \param controller Controller that will act on the State in response to the actions of the Phenomenon; reference stored in \c _controller.
	 * */
	State(const Phenomenon& phenomenon, const Controller& controller);
	virtual ~State();
};

}}

#endif /* STATE_H_ */
