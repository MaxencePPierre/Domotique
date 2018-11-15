/*
 * \file Random.h
 *
 *  \date 13 Nov 2018
 *	\author pcoo34
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include <random>

#include "Phenomenon.h"

namespace domotique { namespace actor { namespace phenomenon {

class Random: public Phenomenon{
private:
	std::default_random_engine _generator;
	std::uniform_real_distribution<double> _distribution;
	const double _valueLow;
	const double _valueHigh;
public:
	void Calculate();
	Random(double influence, const double valueLow, const double valueHigh);
	virtual ~Random();
};

}}}

#endif /* RANDOM_H_ */
