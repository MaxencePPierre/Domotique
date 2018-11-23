/*
 * \file State.h
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#ifndef STATE_H_
#define STATE_H_

#include <memory>

#include "Actor.h"

#include "Phenomenon.h"
#include "Controller.h"

#include "tinyxml2.h"

namespace domotique{ namespace actor {
/**
 * \brief The state upon which the Phenomenon and Controller act
 */
class State: public Actor {
	//TODO: Add a longer description
private:
	std::shared_ptr<Phenomenon> _phenomenon;
	std::shared_ptr<Controller> _controller;
	double _influencePhenomenon;
	double _influenceController;
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
	 * \param iP Influence of Phenomenon
	 * \param iC Influence of Controller
	 * */
	State(std::shared_ptr<Phenomenon> phenomenon, std::shared_ptr<Controller> controller, double iP, double iC)
	: _phenomenon(phenomenon), _controller(controller), _influencePhenomenon(iP), _influenceController(iC) {}
	State(std::shared_ptr<Phenomenon> phenomenon, std::shared_ptr<Controller> controller, tinyxml2::XMLNode * node);
	virtual ~State();

	State& operator=(const State& other)
	{
	    if (this != &other) {
	        _phenomenon = other._phenomenon;
	        _controller = other._controller;
	    }
	    return *this;
	}
};

}}

#endif /* STATE_H_ */
