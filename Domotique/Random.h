/*
 * Random.h
 *
 *  Created on: 13 Nov 2018
 *      Author: pcoo34
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
	double _valueLow;
	double _valueHigh;
public:
	void Calculate();
	Random(double influence, double valueLow, double valueHigh);
	virtual ~Random();
};

}}}

#endif /* RANDOM_H_ */
