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
#include <vector>
//using namespace std;
#include <fstream>
#include "Process.h"

namespace domotique { namespace server {


const std::string end("\n");
const std::string tab("\t");

class Server {
private:
	std::vector<std::string> filenames;

public:
	Server();
	Server(std::string file);
	virtual ~Server();

	// Attributes
	//string logFile; // Name of the output logFile

	// Functions
	//string getLogFile();
	//void setLogFile(string fileName);
	void initLog(int triplet);
	void dataLog(domotique::process::Process& triplet, int process, int tick);



};
}}
#endif /* SERVER_H_ */
