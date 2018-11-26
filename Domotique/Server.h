/*
 * Server.h
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <string>
using namespace std;
#include <fstream>

class Server {
public:
	Server();
	Server(string file);
	virtual ~Server();

	// Attributes
	//string logFile; // Name of the output logFile

	// Functions
	//string getLogFile();
	//void setLogFile(string fileName);
	void initLog(int triplet);
	void dataLog(double data, int triplet);



};

#endif /* SERVER_H_ */
