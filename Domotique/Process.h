/*
 * Process.h
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#ifndef PROCESS_H_
#define PROCESS_H_

#include <map>

#include "Phenomenon.h"
#include "Controller.h"
#include "State.h"

namespace domotique { namespace process {

enum ActorType { Phenomenon, Controller, State };

class Process {
private:
	actor::Phenomenon& _phenomenon;
	actor::State& _state;
	actor::Controller& _controller;
public:
	void CalculateAll();
	std::map<ActorType, double> Values();
	Process(actor::Phenomenon& phenomenon, actor::State& state, actor::Controller& controller);
	virtual ~Process();
};

}}

#endif /* PROCESS_H_ */
