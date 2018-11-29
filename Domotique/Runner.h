/*
 * Runner.h
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#ifndef RUNNER_H_
#define RUNNER_H_

#include <vector>

#include "Server.h"
#include "Process.h"
#include "XMLParseable.h"

namespace domotique {
namespace runner {

/// Class that oversees execution of simulation
class Runner : public xml::XMLParseable {
private:
	std::vector<process::Process *> _triplets;

	std::unique_ptr<server::Server> _monServer;
	unsigned _ticks = 0;

public:
	/**@brief Constructs runner, given name of config file
	 *
	 * @param configFileName Name of xml config file */
	Runner(std::string configFileName);
	Runner();
	virtual ~Runner();

	// Functions
	/// function that initiates the simulation, contains the simulation loop
	void run();
};

}
}

#endif /* RUNNER_H_ */
