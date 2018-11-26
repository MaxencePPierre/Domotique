/*
 * Server.cpp
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#include "Server.h"

#include <vector>

using namespace std;

namespace domotique { namespace server {

Server::Server() {
	filenames.push_back("Process_A");
	filenames.push_back("Process_B");
	//logFile("")
}
/*
Server::Server(string fileName) :
	logFile(fileName)
{}*/

Server::~Server() {
	// TODO Auto-generated destructor stub
}

/*
string Server::getLogFile() {
	//return this->logFile;
}

void Server::setLogFile(string fileName) {
	this->logFile = fileName;
}*/

void Server::initLog(int triplet) {

	string folder = "../log/";
	string fileName = filenames[triplet];

	/*if(triplet == 0) {
		fileName = "Process A";
	}
	else {
		fileName = "Process B";
	}*/

	string path = string(folder) + string(fileName) + string(".txt");
	cout << "Writing into : " << path << endl;

	string metadata = "# Tick		State		Phen		Ctrl\n";

	ofstream myfile;
	myfile.open (path.c_str());//, ios::out | ios::app | ios::binary);
	myfile << "#" + fileName + domotique::server::end;
	myfile << metadata;
	myfile.close();

	cout << path << " have been initialized." << endl;
}

void Server::dataLog(domotique::process::Process& triplet, int process, int tick) {



	string folder = "../log/";
	string fileName = filenames[process] ;

	/*if(triplet == 0) {
		fileName = "Process_A";
	}
	else {
		fileName = "Process_B";
	}*/
	string path = string(folder) + string(fileName)  + string(".txt");
	cout << "Writing into : " << path << endl;



	ofstream myfile;
	myfile.open (path.c_str(), ios::out | ios::app | ios::binary);
	myfile 	<< tick << "\t\t"
			<< triplet.Values()[process::ActorType::State] << "\t"
			<< triplet.Values()[process::ActorType::Phenomenon] << "\t"
			<< triplet.Values()[process::ActorType::Controller] << "\n";
	myfile.close();

	cout << path << "Data have been added to : " << path << endl;

}

}}
