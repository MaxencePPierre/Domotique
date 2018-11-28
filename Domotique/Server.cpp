/*
 * Server.cpp
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#include "Server.h"

#include <vector>

#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

namespace domotique {
namespace server {

Server::Server() {}

Server::Server(std::string fileName) {

	filenames.push_back("Process_A");
	filenames.push_back("Process_B");

	string folder = "log/";
	const string metadata = "# Tick	\tState	\tPhen	\tCtrl\n";

	for (auto name : filenames) {
		string path = string(folder) + string(name) + string(".txt");

		logFileStreams.emplace_back(std::shared_ptr<std::ofstream>(new ofstream(path.c_str(), ios::out | ios::trunc )));
		*logFileStreams.back() << "#" + name + domotique::server::end << metadata;

		cout << "Opening " << path << " for writing." << endl;
	}

}

Server::~Server() {
	for (auto file : logFileStreams)
		file->close();
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
	(*logFileStreams.at(process)) << tick << "\t\t" << std::setw(fieldWidth)
			<< triplet.Values()[process::ActorType::State] << "\t" << std::setw(fieldWidth)
			<< triplet.Values()[process::ActorType::Phenomenon] << "\t" << std::setw(fieldWidth)
			<< triplet.Values()[process::ActorType::Controller] << "\n";

}

}
}
