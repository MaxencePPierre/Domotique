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

///@brief Server class, logs informational messages and gnuplot data
class Server {
private:
	const int fieldWidth = 8;
	std::vector<std::string> filenames;
	std::vector<std::shared_ptr<std::ofstream>> plotDataFiles;
	std::unique_ptr<std::ofstream> logFile;

public:
	Server();
	/// @brief Constructs server given name of output folder @param outputFolder Name of folder to put output in @note The output folder must exist
	Server(std::string outputFolder);
	virtual ~Server();

	// Attributes
	//string logFile; // Name of the output logFile

	// Functions
	//string getLogFile();
	//void setLogFile(string fileName);
	/** @brief logs data produced by triplet
	 * @param triplet reference to Actor triplet
	 * @param process indexes plotDataFiles to determine which output stream to write to
	 * @param tick current tick
	*/
	void dataLog(domotique::process::Process& triplet, int process, int tick);
	/**
	 * \brief Templated stream input operator for logging
	 * For types with predefined operator<< functions in the stl like const char * and std::string.
	 * Ouputs a timestamp in the local time with each log entry.
	 * One call to this function causes one line to be added in the log file. For more complex log entries the operator<< function is defined below for std::stringstream.
	 * \param s Reference to the Server object being written to ( the one doing the logging )
	 * \param t Reference to the templated object being logged
	 * */
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
	/**
	 * \brief Specific stream input operator for logging std::stringstream types
	 * Useful when a more complicated message needs to be logged, containing several types. The std::stringstream object is created, the message is written to it, a reference is passed, the string representation is passed to the templated operator<< function to be written to the log file.
	 * \param s Reference to the Server object owning the log file (left operand).
	 * \param str Reference to the std::stringstream object containing the log message.
	 * */
	friend void operator<<(Server& s, std::stringstream& str)
	{
		std::string string = str.str();
		s << string ;
	}

};
}}
#endif /* SERVER_H_ */
