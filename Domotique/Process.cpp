/*
 * Process.cpp
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#include "Process.h"

namespace domotique { namespace process {

void Process::CalculateAll()
{
	_phenomenon.Calculate();
	_controller.Calculate();
	_state.Calculate();
}

std::map<ActorType, double> Process::Values()
{
	return {
		{Phenomenon, _phenomenon.Value()},
		{Controller, _controller.Value()},
		{State, _state.Value()}
	};
}

Process::Process(actor::Phenomenon& phenomeonon, actor::State& state, actor::Controller& controller)
: _phenomenon(phenomeonon), _state(state), _controller(controller) {
	// TODO Auto-generated constructor stub

}

Process::~Process() {
	// TODO Auto-generated destructor stub
}

}}
