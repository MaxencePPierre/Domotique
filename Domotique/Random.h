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
#include "tinyxml2.h"

namespace domotique { namespace actor { namespace phenomenon {

class Random: public Phenomenon{
private:
	std::default_random_engine _generator;
	std::uniform_real_distribution<double> _distribution;
	double _valueLow;
	double _valueHigh;
public:
	void Calculate();
	Random(const double valueLow, const double valueHigh);
	Random(tinyxml2::XMLNode * node);
	Random(Random* r){this->_distribution = r->_distribution;}
	virtual ~Random();
};

}}}

#endif /* RANDOM_H_ */
