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

class Runner : public xml::XMLParseable {
private:
	std::vector<process::Process *> _triplets;

	server::Server _monServer;
	unsigned _ticks = 0;

public:
	Runner(std::string configFileName);
	Runner();
	virtual ~Runner();

	// Attributes
	server::Server _server;

	// Functions
	void run();
};

}
}

#endif /* RUNNER_H_ */
