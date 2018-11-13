/*
 * Process.cpp
 *
 *  Created on: 12 Nov 2018
 *      Author: pcoo34
 */

#include "Process.h"

namespace domotique {
namespace process {

Process::Process(Process& phenomeonon, Process& state, Process& controller)
: _phenomenon(phenomeonon), _state(state), _controller(controller) {
	// TODO Auto-generated constructor stub

}

Process::~Process() {
	// TODO Auto-generated destructor stub
}

} /* namespace process */
} /* namespace domotique */
