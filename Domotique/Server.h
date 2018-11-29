/*
 * Server.h
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <fstream>
#include <ctime>

#include "Process.h"

namespace domotique { namespace server {


const std::string end("\n");
const std::string tab("\t");
const std::string separator("/");
const std::string defaultOutputFolder = "log";
const std::string logFileName = "domotique.log";

class Server {
private:
	const int fieldWidth = 8;
	std::vector<std::string> filenames;
	std::vector<std::shared_ptr<std::ofstream>> plotDataFiles;
	std::unique_ptr<std::ofstream> logFile;

public:
	Server();
	Server(std::string fileName);
	virtual ~Server();

	// Attributes
	//string logFile; // Name of the output logFile

	// Functions
	//string getLogFile();
	//void setLogFile(string fileName);
	void dataLog(domotique::process::Process& triplet, int process, int tick);
	template<typename T>
	friend void operator<<(Server& s, T& t)
	{
		std::time_t time = std::time(0);
		std::tm* now = std::localtime(&time);
		*(s.logFile)
				<< "["
				<< (now->tm_year + 1900) << "-" << (now->tm_mon) << "-" << (now->tm_mday) << "T"
				<< (now->tm_hour) << ":" << (now->tm_min) << ":" << (now->tm_sec) << " " << (now->tm_zone)
				<< "]" << " "
				<< t << std::endl;
	}

	friend void operator<<(Server& s, std::stringstream& str)
	{
		std::string string = str.str();
		s << string ;
	}

};
}}
#endif /* SERVER_H_ */
