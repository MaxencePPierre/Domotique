/*
 * Server.cpp
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#include "Server.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace tinyxml2;

namespace domotique {
namespace server {

Server::Server()
		: _tick( 0 )
{
	string logPath = logFileName;
	logFile.reset( new std::ofstream( logPath.c_str(), ios::out | ios::trunc ) );
	std::cout << "Log file " << logFileName << " created\n";
	std::stringstream s;
	s << "Server created";
	*this << s;
	string path = outputFileName;
	plotDataFiles.emplace_back( std::shared_ptr< std::ofstream >( new ofstream( path.c_str(), ios::out | ios::trunc ) ) );
	*plotDataFiles.back() << "Tick" ;
	s.str( "" );
	s.clear();
	s << "Opened gnuplot data file " << path << end;
	cout << s.str();
	*this << s;
}

//Server::Server(vector<shared_ptr<actor::Actor>>& actors, vector<std::string>& zoneNames)		: _tick( 0 ), filenames(zoneNames)
Server::Server(XMLNode * node) : Server()
{

	//filenames.push_back( "data.gp" );
	//filenames.push_back( "Process_B.gp" );

	//const string metadata = "Tick\tState\tPhenomenon\tController\tState\tPhenomenon\tController";

//	for( auto name : filenames )
//	{
//		string path = name;
//
//		plotDataFiles.emplace_back( std::shared_ptr< std::ofstream >( new ofstream( path.c_str(), ios::out | ios::trunc ) ) );
//		*plotDataFiles.back() << "#" + name + domotique::server::end;
//
//		cout << "Opening gnuplot data file " << path << " for writing." << endl;
//	}

}

void Server::newZone(std::string zoneName)
{
	std::stringstream s;
	s << "Starting new zone : " << zoneName;
//	string path = zoneName + gnuplotExtension;
//	plotDataFiles.emplace_back( std::shared_ptr< std::ofstream >( new ofstream( path.c_str(), ios::out | ios::trunc ) ) );
//	*plotDataFiles.back() << "#" << zoneName << end << "Tick" ;
//	s.str( "" );
//	s.clear();
//	s << "Opened gnuplot data file " << path << end;
//	cout << s.str();
//	*this << s;
}

void Server::newActor(std::string zoneName, std::string actorName)
{
	std::stringstream s;
	s << "Created new actor : " << actorName;
	*this << s;
	// For gnuplot header names
	std::replace(actorName.begin(), actorName.end(), ' ', '_');
	std::replace(actorName.begin(), actorName.end(), '/', '_');
	std::replace(zoneName.begin(), zoneName.end(), ' ', '_');
	std::replace(zoneName.begin(), zoneName.end(), '/', '_');

	*plotDataFiles.back() << "\t" + zoneName + '_' + actorName;
}

Server::~Server()
{
	for( auto file : plotDataFiles )
	{
		*file << end;
		file->close();
	}
	*this << "Simulation finished";
	logFile->close();
}

void Server::nextTick()
{
	*plotDataFiles.at( 0 ) << std::endl << _tick << "\t\t";
	_tick++;
}
void Server::dataLog(double value)
{
	*plotDataFiles.at( 0 ) << " " << setw( fieldWidth ) << value;
}

}
}
