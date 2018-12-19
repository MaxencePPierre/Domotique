/*
 * \file Pulsed.h
 *
 * \date 10 Dec 2018
 * \author pcoo34
 */

#ifndef PULSED_H_
#define PULSED_H_

#include "Phenomenon.h"
#include "tinyxml2.h"

namespace domotique {
namespace actor {
namespace phenomenon {

class Pulsed: public Phenomenon
{
	public:
		void Calculate(int tick) override;
		Pulsed(tinyxml2::XMLNode * node);
		virtual ~Pulsed(){};
};

}
}
}

#endif /* PULSED_H_ */
