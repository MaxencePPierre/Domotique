/*
 * main.cpp
 *
 *  Created on: 19 nov. 2018
 *      Author: pcoo30
 */


#include "Server.h"

int main() {

	Server monServer = Server();

	monServer.initLog(0);
	monServer.initLog(1);


	monServer.dataLog(12.6, 0);
	monServer.dataLog(98.3, 1);


	return 0;
}



