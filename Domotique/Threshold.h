/*
 * \file Threshold.h
 *
 * \date 13 Nov 2018
 * \author pcoo34
 */

#ifndef THRESHOLD_H_
#define THRESHOLD_H_

#include <memory>

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
//	static std::map<const std::string, xml::XMLMap::Element> _requiredParams;
//	static std::map<const std::string, xml::XMLMap::Element> _optionalParams;
//	std::map<xml::XMLMap::Element, double> _paramList;
	/// Phenomenon from which to take the value
	std::shared_ptr<Phenomenon> _phenomenon;
public:
	/// Formula: \f$value = min\{\text{Value}_{saturation}, \text{Value}_{phenomenon}\}\f$
	void Calculate();

	/**
	 * \param node XMLNode which contains the parameters from which to construct the Threshold Controller
	 * \param phenomenon Copied to _phenomenon
	 */
	Threshold(tinyxml2::XMLNode * node, std::shared_ptr<Phenomenon> phenomenon);
	/** Copy constructor
	 * \brief Copies non-static members from t */
	Threshold(Threshold* t);
	virtual ~Threshold();
};

}}}

#endif /* THRESHOLD_H_ */
