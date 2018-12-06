/*
 * Runner.cpp
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#include "Runner.h"

#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>

#include "Server.h"
#include "tinyxml2.h"
#include "XMLMappings.h"
#include <sstream>
#include "Controller.h"
#include "Phenomenon.h"
#include "State.h"
#include <iostream>
#include "Controller.h"
#include "Phenomenon.h"
#include "State.h"
#include "tinyxml2.h"
#include "XMLMappings.h"

using namespace tinyxml2;
using namespace domotique::xml;

namespace domotique {
namespace runner {

Runner::Runner(std::string configFileName)
{
	XMLDocument config;
	if( XMLError::XML_SUCCESS != config.LoadFile( configFileName.c_str() ) )
		throw xml::XMLParseException( "Failed to open config file", __FILE__, __LINE__ );
	XMLElement* root = config.RootElement();

	// TODO: get filepath from xmlfile
	// is unique pointer now => destructor called at destruction of this class, not when object goes out of scope :)
	_monServer = std::unique_ptr< server::Server >( new server::Server( "." ) );
	*_monServer << "Server created";
	std::vector< XMLElement * > children;
	for( XMLElement * child = root->FirstChildElement( xml::XMLMap::BaseElementMap.at( xml::XMLMap::Element::Zone ).c_str() ); child;
			child = child->NextSiblingElement( xml::XMLMap::BaseElementMap.at( xml::XMLMap::Element::Zone ).c_str() ) )
	{
		*_monServer << "Starting new zone";
		// Pointers to the phenomenon and controller the state will act upon
		std::shared_ptr< actor::Phenomenon > phenomenon;
		std::shared_ptr< actor::Controller > controller;
		for( XMLNode * node = child->FirstChild(); node; node = node->NextSibling() )
		{
			XMLMap::Element actorType = XMLMap::ElementMap.at( node->Value() );
			switch(actorType)
			{
				case XMLMap::Element::Phenomenon:
					phenomenon = actor::Phenomenon::makePhenomenon( node );
					_actors.push_back( phenomenon );
					break;
				case XMLMap::Element::Controller:
					controller = actor::Controller::makeController( node );
					_actors.push_back( controller );
					break;
				case XMLMap::Element::State:
				{

					std::shared_ptr< actor::State > state = std::make_shared< actor::State >( phenomenon, controller, node );
					_actors.push_back( state );
					controller->registerState( state );
					break;
				}
				default:
					throw XMLParseException( "Type not recognised", __FILE__,
					__LINE__ );
					break;
			};
			std::stringstream s;
			s << "Created new " << node->Value() << " actor";
			*_monServer << s;
		}
		*_monServer << "Finished zone";
	}

	_requiredParams =
	{
		{	xml::XMLMap::Element::Ticks}
	};
	_optionalParams =
	{};

	XMLElement * runnerNode = root->FirstChildElement( xml::XMLMap::BaseElementMap.at( xml::XMLMap::Element::Runner ).c_str() );
	if( !runnerNode ) throw xml::XMLParseException( "Necessary runner element not found", __FILE__, __LINE__ );
	populate( runnerNode );
	std::stringstream s;
	s << "Preparing to run simulation for " << _paramList[xml::XMLMap::Element::Ticks] << " ticks";
	*_monServer << s;
}

Runner::~Runner()
{
}
Runner::Runner()
{
}

void Runner::run()
{
	*_monServer << "Simulation started";
	unsigned nticks = static_cast< unsigned >( _paramList[xml::XMLMap::Element::Ticks] );
	for( unsigned i = 0; i < nticks; i++ )
	{
		if( i % 10 == 0 )
		{
			std::stringstream s;
			s << "Tick " << i;
			*_monServer << s;
		}
		_monServer->nextTick();
		for( auto actor : _actors )
		{
			actor->Calculate( i );
			_monServer->dataLog( actor->Value() );
		}
	}
	*_monServer << "Simulation completed successfully";
}
}
}
