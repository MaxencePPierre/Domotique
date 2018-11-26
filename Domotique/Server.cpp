/*
 * Server.cpp
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#include "Server.h"

string end = string("\n");
string tab = string("	");


Server::Server() {
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
	string fileName;

	if(triplet == 0) {
		fileName = "Process A";
	}
	else {
		fileName = "Process B";
	}

	string path = string(folder) + string(fileName) + string(".txt");
	cout << "Writing into : " << path << endl;

	string metadata = "# Tick		State		Phen		Ctrl\n";

	ofstream myfile;
	myfile.open (path.c_str());//, ios::out | ios::app | ios::binary);
	myfile << fileName + end;
	myfile << metadata;
	myfile.close();

	cout << path << " have been initialized." << endl;
}

void Server::dataLog(double data, int triplet) {

	string folder = "../log/";
	string fileName;

	if(triplet == 0) {
		fileName = "Process A";
	}
	else {
		fileName = "Process B";
	}
	string path = string(folder) + string(fileName)  + string(".txt");
	cout << "Writing into : " << path << endl;

	ofstream myfile;
	myfile.open (path.c_str(), ios::out | ios::app | ios::binary);
	myfile << data;
	myfile.close();

	cout << path << "Data have been added to : " << path << endl;

}


