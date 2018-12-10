/*
 * Runner.h
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#ifndef RUNNER_H_
#define RUNNER_H_

#include <memory>
#include <string>
#include <vector>

#include "Actor.h"
#include "Server.h"
#include "XMLParseable.h"

namespace domotique {
namespace runner {

/// Class that oversees execution of simulation
class Runner: public xml::XMLParseable
{
	private:
		std::vector<std::shared_ptr<actor::Actor>> _actors;
		std::unique_ptr< server::Server > _monServer;
		unsigned _ticks = 0;

	public:
		/**@brief Constructs runner, given name of config file
		 *
		 * @param configFileName Name of xml config file */
		Runner(std::string configFileName);
		Runner();
		virtual ~Runner();

		/// function that initiates the simulation, contains the simulation loop
		void run();
};

}
}

#endif /* RUNNER_H_ */
