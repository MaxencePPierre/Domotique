/*
 * Runner.cpp
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#include "Runner.h"
#include <map>

#include "Process.h"
#include "Server.h"
#include "tinyxml2.h"
#include "XMLMappings.h"
#include <sstream>

using namespace tinyxml2;

namespace domotique {
namespace runner {

Runner::Runner(std::string configFileName) {
	XMLDocument config;
	if(XMLError::XML_SUCCESS != config.LoadFile(configFileName.c_str()))
		throw xml::XMLParseException("Failed to open config file", __FILE__, __LINE__);
	XMLElement* root = config.RootElement();

	// TODO: get filepath from xmlfile
	// is unique pointer now => destructor called at destruction of this class, not when object goes out of scope :)
	_monServer = std::unique_ptr<server::Server>(new server::Server("."));
	*_monServer << "Server created";
	std::vector<XMLElement *> children;
	for (XMLElement * child =
			root->FirstChildElement(
					xml::XMLMap::BaseElementMap.at(
							xml::XMLMap::Element::Process).c_str());
			child;
			child = child->NextSiblingElement(
					xml::XMLMap::BaseElementMap.at(
							xml::XMLMap::Element::Process).c_str()))
	{
		// TODO : Process name output file
		children.push_back(child);
	}
	for (auto * child : children) {
		_triplets.push_back(new process::Process(child));
		*_monServer << "Created new process";
	}
	_requiredParams =
	{
			{xml::XMLMap::Element::Ticks}
	};
	_optionalParams = {};

	XMLElement * runnerNode = root->FirstChildElement(
			xml::XMLMap::BaseElementMap.at(
					xml::XMLMap::Element::Runner).c_str());
	if (!runnerNode)
		throw xml::XMLParseException("Necessary runner element not found", __FILE__, __LINE__);
	populate(runnerNode);
	std::stringstream s;
	s << "Running simulation for " << _paramList[xml::XMLMap::Element::Ticks] << " ticks";
	*_monServer << s;
}

Runner::~Runner() {
	for(auto * t : _triplets)
		delete t;
}
Runner::Runner() {
	// TODO Auto-generated constructor stub
}

void Runner::run() {
	*_monServer << "Simulation started";
	for (unsigned i = 0; i < _paramList[xml::XMLMap::Element::Ticks]; i++) {
		for (unsigned p = 0; p < _triplets.size(); p++) {
			_triplets[p]->CalculateAll();
			(_monServer)->dataLog(*_triplets[p], p, i);
		}
	}
	*_monServer << "Simulation ended";
}
}
}
