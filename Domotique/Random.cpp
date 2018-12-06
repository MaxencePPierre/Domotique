/*
 * \file Random.cpp
 *
 * \date 13 Nov 2018
 * \author pcoo34
 */
#include <vector>

#include "Random.h"
#include "tinyxml2.h"
#include "XMLMappings.h"
#include "XMLParseable.h"

using namespace tinyxml2;
using namespace domotique::xml;

namespace domotique { namespace actor { namespace phenomenon {

void Random::Calculate(int tick)
{
	_value = _distribution(_generator);
}


Random::Random(tinyxml2::XMLNode * node)
{
	_requiredParams =
	{
			{XMLMap::Element::ValueHigh},
			{XMLMap::Element::ValueLow}
	};
	_optionalParams =
	{

	};
	populate(node);
	_distribution = std::uniform_real_distribution<double>(_paramList[XMLMap::Element::ValueLow], _paramList[XMLMap::Element::ValueHigh]);
}

Random::~Random() {
	// TODO Auto-generated destructor stub
}

}}}
