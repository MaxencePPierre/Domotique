/*
 * \file Phenomenon.cpp
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#include "Phenomenon.h"

#include <map>
#include <random>
#include <string>

#include "Random.h"
#include "Sinusoidal.h"
#include "XMLMappings.h"

using namespace tinyxml2;
using namespace domotique::actor::phenomenon;
using namespace domotique::xml;

namespace domotique {
namespace actor {

double Phenomenon::BoxMuller(double mu, double sigma)
{
	std::default_random_engine generator;
	std::uniform_real_distribution<double> uniform(0.0, 1.0);
	// uniform random variables E ]0,1[
	double x1 = uniform(generator);
	double x2 = uniform(generator);

	// As uniform(generator) returns values in [0.0,1.0[, need to ensure x1, x2 =/= 0 as specified
	while(0 == x1) x1 = uniform(generator);
	while(0 == x2) x2 = uniform(generator);

	double y = std::sqrt(-2 * std::log(x1)) * std::cos(2 * pi * x2);
	double z = mu + (y * sigma);
	return z;
}

std::shared_ptr< Phenomenon > Phenomenon::makePhenomenon(XMLNode * node)
{
	std::shared_ptr< Phenomenon > phenomenon;
	ElementType type = ElementTypeMap.at(
			node->ToElement()->FindAttribute( AttributeMap.at(Attributes::Type).c_str() )->Value() );
	switch(type)
	{
		case ElementType::Sinusoidal:
			phenomenon.reset( new Sinusoidal( node ) );
			break;
		case ElementType::Random:
			phenomenon.reset( new Random( node ) );
			break;
		default:
			throw xml::XMLParseException( "Type of phenomenon not recognised", __FILE__, __LINE__ );
			break;
	}
	return phenomenon;
}
}
}
