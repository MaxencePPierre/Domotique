/*
 * \file Sinusoidal.cpp
 *
 * \date Dec 6, 2018
 * \author pcoo34
 */

#include "Sinusoidal.h"

#include <cmath>
#include <initializer_list>
#include <limits>
#include <map>
#include <set>

#include "XMLMappings.h"

using namespace tinyxml2;
using domotique::xml::Element;;
using domotique::xml::XMLParseException;

namespace domotique {
namespace actor {
namespace phenomenon {

void Sinusoidal::Calculate(int tick)
{
	//TODO verify that this works
	double intermediateValue = _paramList[Element::OFFS]
			+ _paramList[Element::AMPL]
					* std::sin(
							( 2 * pi * ( tick + static_cast< long int >( _paramList[Element::PHASE] ) ) )
									/ ( static_cast< long int >( _paramList[Element::PERIOD] ) ) );
	intermediateValue = BoxMuller(intermediateValue);
	if(intermediateValue > _paramList[Element::SAT_MAX])
		_value = _paramList[Element::SAT_MAX];
	else if(intermediateValue < _paramList[Element::SAT_MIN])
		_value = _paramList[Element::SAT_MIN];
	else
	_value = intermediateValue;
}

Sinusoidal::Sinusoidal(XMLNode * node)
{
	_requiredParams =
	{
		Element::AMPL,
		Element::PERIOD
	};
	_optionalParams =
	{
		{	Element::OFFS , 0.0},
		{	Element::PHASE , 0.0},
		{	Element::SAT_MAX , std::numeric_limits<double>::infinity()},
		{	Element::SAT_MIN , -std::numeric_limits<double>::infinity()}
	};

	populate(node);
	// Check validity of parameters
	if(_paramList[Element::PERIOD] <= 0)
	throw XMLParseException("Period of a sinusoidal phenomenon cannot be negative", __FILE__, __LINE__);
	if(_paramList[Element::SAT_MAX] < _paramList[Element::SAT_MIN])
	throw XMLParseException("For sinusoidal phenomenon: SAT_MAX should be greater than SAT_MIN", __FILE__, __LINE__);
}

}
}
}
