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
#include <map>
#include <set>

#include "XMLMappings.h"

using namespace std;
using namespace tinyxml2;
using namespace domotique::xml;

namespace domotique {
namespace server {

Server::Server(XMLNode * node)
		: _tick( 0 ) // : Server()
{
	std::cout << "Creating Server\n";
	for( XMLElement * child = node->FirstChildElement(); child; child = child->NextSiblingElement() )
	{
		Element elem = ElementMap.at(child->Name());
		switch(elem)
		{
			case Element::LogFileName:
			{
				std::string logFileName( child->GetText() );
				if( logFileName.empty() ) throw XMLParseException( "Log file name must not be empty", __FILE__, __LINE__ );
				logFile.reset( new std::ofstream( logFileName, ios::out | ios::trunc ) );

				std::cout << "Log file " << logFileName << " created\n";
				*this << "Server created";
				break;
			}
			case Element::DataFileName:
			{	std::string dataFileName( child->GetText() );
				if( dataFileName.empty() ) throw XMLParseException( "Output data file name must not be empty", __FILE__, __LINE__ );
				dataFile.reset( new ofstream( dataFileName, ios::out | ios::trunc ) );
				*dataFile << "Tick";

				std::stringstream s;
				s << "Data file " << dataFileName << " created";
				*this << s;
				s << std::endl;
				cout << s.str();
				break;
			}
			default:
				throw XMLParseException( "Undefined argument in server", __FILE__, __LINE__);
		};
	}
}

void Server::newZone(std::string zoneName)
{
	std::stringstream s;
	s << "Starting new zone : " << zoneName;
}

void Server::newActor(std::string zoneName, std::string actorName)
{
	std::stringstream s;
	s << "Created new actor : " << actorName;
	*this << s;
	// For gnuplot header names
	std::replace( actorName.begin(), actorName.end(), ' ', '_' );
	std::replace( actorName.begin(), actorName.end(), '/', '_' );
	std::replace( zoneName.begin(), zoneName.end(), ' ', '_' );
	std::replace( zoneName.begin(), zoneName.end(), '/', '_' );

	*dataFile << "\t" + zoneName + '_' + actorName;
}

Server::~Server()
{
	dataFile->close();
	*this << "Simulation finished";
	logFile->close();
}

void Server::nextTick()
{
	*dataFile  << std::endl << _tick << "\t\t";
	_tick++;
}
void Server::dataLog(double value)
{
	 *dataFile << " " << setw( fieldWidth ) << value;
}

}
}
