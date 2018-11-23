/*
 * Process.h
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#ifndef PROCESS_H_
#define PROCESS_H_

#include <map>
#include <memory>

#include "tinyxml2.h"

#include "Phenomenon.h"
#include "Controller.h"
#include "State.h"

namespace domotique { namespace process {

enum ActorType { Phenomenon, Controller, State };

class Process {
private:
	std::shared_ptr<actor::Phenomenon> _phenomenon;
	std::shared_ptr<actor::Controller> _controller;
	std::unique_ptr<actor::State> _state;

public:
	void CalculateAll();
	std::map<ActorType, double> Values();
	Process(tinyxml2::XMLNode *node);
	virtual ~Process();
};

}}

#endif /* PROCESS_H_ */
