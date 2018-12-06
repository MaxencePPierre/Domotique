/*
 * Server.cpp
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#include "Server.h"

#include <iomanip>
#include <iostream>

using namespace std;

namespace domotique {
namespace server {

Server::Server()
		: _tick( 0 )
{
}

Server::Server(std::string outputFolder)
		: _tick( 0 )
{
	string logPath = outputFolder + separator + logFileName;
	logFile.reset( new std::ofstream( logPath.c_str(), ios::out | ios::trunc ) );
	std::stringstream s;
	s << "Log file " << logFileName << " created";
	*this << "Log file created";
	filenames.push_back( "data.gp" );
	filenames.push_back( "Process_B" );

	const string metadata = "Tick\tState\tPhenomenon\tController\tState\tPhenomenon\tController";

	for( auto name : filenames )
	{
		string path = outputFolder + separator + string( name );

		plotDataFiles.emplace_back( std::shared_ptr< std::ofstream >( new ofstream( path.c_str(), ios::out | ios::trunc ) ) );
		*plotDataFiles.back() << "#" + name + domotique::server::end << metadata;

		cout << "Opening gnuplot data file " << path << " for writing." << endl;
	}

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
