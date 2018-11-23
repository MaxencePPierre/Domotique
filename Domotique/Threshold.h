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

#include "XmlParse.h"
#include "tinyxml2.h"

namespace domotique{ namespace actor{ namespace controller {

/**
 * \brief Dummy Controller implementation for phase one of project
 *
 * A controller which calculates a value for the state based on the value of the phenomenon.
 * It does so by imposing an upper bound, the value of the member variable _saturation.
 */
class Threshold: public Controller {
private:
	static std::map<const std::string, xml::XMLMap::Element> _requiredParams;
	static std::map<const std::string, xml::XMLMap::Element> _optionalParams;
	std::map<xml::XMLMap::Element, double> _paramList;
	/// Phenomenon from which to take the value
	const Phenomenon* _phenomenon;
public:
	/// Formula: \f$value = min\{\text{Value}_{saturation}, \text{Value}_{phenomenon}\}\f$
	void Calculate();

	/**
	 * \param phenomenon Copied to _phenomenon
	 */
	Threshold(double saturation, const Phenomenon * phenomenon);
	Threshold(tinyxml2::XMLNode * node, const Phenomenon* phenomenon);
	virtual ~Threshold();
};

}}}

#endif /* THRESHOLD_H_ */
