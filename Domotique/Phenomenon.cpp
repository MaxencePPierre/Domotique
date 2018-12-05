/*
 * \file Phenomenon.cpp
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#include "Phenomenon.h"
#include "Random.h"
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace domotique::actor::phenomenon;

namespace domotique {
namespace actor {
std::shared_ptr< Phenomenon > Phenomenon::makePhenomenon(XMLNode * node)
{
	std::shared_ptr< Phenomenon > phenomenon;
	phenomenon.reset( new Random( node ) );
	return phenomenon;
}
}
}
