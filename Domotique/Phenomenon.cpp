/*
 * Phenomenon.cpp
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#include "Phenomenon.h"

namespace domotique{ namespace actor {

double Phenomenon::Influence()
{
	return _influence;
}

Phenomenon::Phenomenon(double influence) : _influence(influence) {
	// TODO Auto-generated constructor stub

}

Phenomenon::~Phenomenon() {
	// TODO Auto-generated destructor stub
}

}}
