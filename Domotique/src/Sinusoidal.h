/*
 * \file Sinusoidal.h
 *
 * \date Dec 6, 2018
 * \author pcoo34
 */

#ifndef SINUSOIDAL_H_
#define SINUSOIDAL_H_

#include "Phenomenon.h"
#include "tinyxml2.h"

namespace domotique {
namespace actor {
namespace phenomenon {

class Sinusoidal: public Phenomenon
{
	public:
		void Calculate(int tick) override;
		Sinusoidal(tinyxml2::XMLNode * node);
};

}
}
}

#endif /* SINUSOIDAL_H_ */
