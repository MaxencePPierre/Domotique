/*
 * Server.h
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <ctime>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include "tinyxml2.h"
#include "XMLParseable.h"

namespace domotique { namespace server {


const std::string end("\n");
const std::string tab("\t");
const std::string separator("/");
const std::string defaultOutputFolder = "log";
const std::string logFileName = "domotique.log";
const std::string gnuplotExtension = ".gp";
const std::string outputFileName = "domotique" + gnuplotExtension;

///@brief Server class, logs informational messages and gnuplot data
class Server : public domotique::xml::XMLParseable {
private:
	const int fieldWidth = 8;
	std::vector<std::string> filenames;
	std::vector<std::shared_ptr<std::ofstream>> plotDataFiles;
	std::unique_ptr<std::ofstream> logFile;
	/// Current tick number
	int _tick;
public:
	Server();
	Server(tinyxml2::XMLNode * node);
	virtual ~Server();
	void nextTick();
	void newZone(std::string zoneName);
	void newActor(std::string zoneName, std::string actorName);
	// Attributes
	//string logFile; // Name of the output logFile

	// Functions
	//string getLogFile();
	//void setLogFile(string fileName);
	/* @brief logs data produced by triplet
	 * @param triplet reference to Actor triplet
	 * @param process indexes plotDataFiles to determine which output stream to write to
	 * @param tick current tick
	*/
//	void dataLog(domotique::zone::Zone& triplet, int process, int tick);
	void dataLog(double value);
	/**
	 * \brief Templated stream input operator for logging.
	 *
	 * For types with predefined \c operator<< functions in the stl like \c const \c char \c * and \c std::string.
	 * Ouputs a timestamp in the local time with each log entry.
	 * One call to this function causes one line to be added in the log file. For more complex log entries the \c operator<< function is defined below for \c std::stringstream.
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
				<< (now->tm_year + 1900) << "-" << (now->tm_mon +1) << "-" << (now->tm_mday) << "T"
				<< (now->tm_hour) << ":" << (now->tm_min) << ":" << (now->tm_sec) << " " << (now->tm_zone)
				<< "]" << " "
				<< t << std::endl;
	}
	/**
	 * \brief Specific stream input operator for logging \c std::stringstream types.
	 *
	 * Useful when a more complicated message needs to be logged, containing several types. The \c std::stringstream object is created, the message is written to it, a reference is passed, the string representation is passed to the templated \c operator<< function to be written to the log file.
	 * \param s Reference to the Server object owning the log file (left operand).
	 * \param str Reference to the \c stringstream object containing the log message.
	 * */
	friend void operator<<(Server& s, std::stringstream& str)
	{
		std::string string = str.str();
		s << string ;
	}

};
}}
#endif /* SERVER_H_ */
