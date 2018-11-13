/*
 * Actor.h
 *
 *  Created on: 13 Nov 2018
 *      Author: pcoo34
 */

#ifndef ACTOR_H_
#define ACTOR_H_

namespace domotique{ namespace actor {

class Actor {
protected:
	double _value = 0;
public:
	virtual void Calculate() = 0;
	double Value() { return _value; };
	Actor();
	virtual ~Actor();
};

}}

#endif /* ACTOR_H_ */
