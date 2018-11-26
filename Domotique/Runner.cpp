/*
 * Runner.cpp
 *
 *  Created on: 12 nov. 2018
 *      Author: pcoo30
 */

#include "Runner.h"
#include <iostream>
#include <map>
#include <exception>

#include "Process.h"
#include "Server.h"
#include "XmlParse.h"
#include "tinyxml2.h"

using namespace tinyxml2;

namespace domotique {
namespace runner {
Runner::Runner(std::string configFileName) {
	_monServer.initLog(0);
	_monServer.initLog(1);

	XMLDocument config;
	config.LoadFile(configFileName.c_str());
	XMLElement* root = config.RootElement();
	_triplets.push_back( new process::Process(
					root->FirstChildElement(
							xml::XMLMap::BaseElementMap.at(
									xml::XMLMap::Element::Process).c_str())));

}

Runner::~Runner() {
	// TODO Auto-generated destructor stub
}
Runner::Runner() {
	// TODO Auto-generated destructor stub
}

void Runner::run(unsigned n) {

	for (unsigned i = 0; i < n; i++) {
		for (unsigned p = 0; p < _triplets.size() ; p++){
			_triplets[p]->CalculateAll();
			_monServer.dataLog(*_triplets[p], 0, i);
		}
	}
}
}
}
