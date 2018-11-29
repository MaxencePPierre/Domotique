/*
 * Server.cpp
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#include "Server.h"

#include <vector>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <memory>

using namespace std;

namespace domotique {
namespace server {

Server::Server() {}

Server::Server(std::string outputFolder) {
	string logPath = outputFolder + separator + logFileName;
	logFile.reset(new std::ofstream(logPath.c_str(), ios::out | ios::trunc ));
	*this << "Log file created";
	filenames.push_back("Process_A");
	filenames.push_back("Process_B");

	const string metadata = "# Tick	\tState	\tPhen	\tCtrl\n";

	for (auto name : filenames) {
		string path = outputFolder + separator + string(name) + string(".gp");

		plotDataFiles.emplace_back(std::shared_ptr<std::ofstream>(new ofstream(path.c_str(), ios::out | ios::trunc )));
		*plotDataFiles.back() << "#" + name + domotique::server::end << metadata;

		cout << "Opening gnuplot data file " << path << " for writing." << endl;
	}

}

Server::~Server() {
	for (auto file : plotDataFiles)
		file->close();
	logFile->close();
}

/*
 string Server::getLogFile() {
 //return this->logFile;
 }

 void Server::setLogFile(string fileName) {
 this->logFile = fileName;
 }*/

void Server::dataLog(domotique::process::Process& triplet, int process, int tick) {
//	cout << "Writing into : " << process << "\n";
	(*plotDataFiles.at(process)) << tick << "\t\t" << std::setw(fieldWidth)
			<< triplet.Values()[process::ActorType::State] << "\t" << std::setw(fieldWidth)
			<< triplet.Values()[process::ActorType::Phenomenon] << "\t" << std::setw(fieldWidth)
			<< triplet.Values()[process::ActorType::Controller] << "\n";
}

}
}
