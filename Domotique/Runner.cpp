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

using namespace tinyxml2;

namespace domotique {
namespace runner {

Runner::Runner(std::string configFileName) {
	XMLDocument config;
	config.LoadFile(configFileName.c_str());
	XMLElement* root = config.RootElement();

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
		children.push_back(child);
	}
	int i = 0;
	for (auto * child : children) {
		_monServer.initLog(i++);
		_triplets.push_back(new process::Process(child));
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
		throw xml::XMLParseException("Necessary element not found", __FILE__, __LINE__);
	populate(runnerNode);
}

Runner::~Runner() {
	// TODO Auto-generated destructor stub
}
Runner::Runner() {
	// TODO Auto-generated constructor stub
}

void Runner::run() {
	for (unsigned i = 0; i < _paramList[xml::XMLMap::Element::Ticks]; i++) {
		for (unsigned p = 0; p < _triplets.size(); p++) {
			_triplets[p]->CalculateAll();
			_monServer.dataLog(*_triplets[p], p, i);
		}
	}
}
}
}
