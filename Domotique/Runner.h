/*
 * Runner.h
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#ifndef RUNNER_H_
#define RUNNER_H_

#include "Server.h"

class Runner {
public:
	Runner();
	virtual ~Runner();

	// Attributes
	Server _server;
	//Process _triplets;



	// Functions
	void run(unsigned n);
};

#endif /* RUNNER_H_ */
