/*
 * \file Threshold.h
 *
 * \date 13 Nov 2018
 * \author pcoo34
 */

#ifndef THRESHOLD_H_
#define THRESHOLD_H_

#include "Controller.h"
#include "Phenomenon.h"

namespace domotique{ namespace actor{ namespace controller {

/**
 * \brief Dummy Controller implementation for phase one of project
 *
 * A controller which calculates a value for the state based on the value of the phenomenon.
 * It does so by imposing an upper bound, the value of the member variable _saturation.
 */
class Threshold: public Controller {
private:
	/// Upper bound for the controller's generated value
	double _saturation;

	/// Phenomenon from which to take the value
	Phenomenon& _phenomenon;
public:
	/// Formula: \f$value = min\{\text{Value}_{saturation}, \text{Value}_{phenomenon}\}\f$
	void Calculate();

	/**
	 * \param influence Passed to superclass's constructor
	 * \param saturation Copied to _saturation
	 * \param phenomenon Copied to _phenomenon
	 */
	Threshold(double influence, double saturation, Phenomenon& phenomenon);
	virtual ~Threshold();
};

}}}

#endif /* THRESHOLD_H_ */
