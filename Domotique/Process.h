/*
 * Process.h
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#ifndef PROCESS_H_
#define PROCESS_H_

#include <map>

namespace domotique {
namespace process {

enum ActorType { Phenomenon, Controller, State };

class Process {
private:
	Process& _phenomenon;
	Process& _state;
	Process& _controller;
public:
	void CalculateAll();
	std::map<ActorType, double> Values();
	Process(Process& phenomenon, Process& state, Process& controller);
	virtual ~Process();
};

} /* namespace process */
} /* namespace domotique */

#endif /* PROCESS_H_ */
