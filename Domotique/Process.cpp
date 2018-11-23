/*
 * \file Process.cpp
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#include <sstream>
#include <string>

#include "Process.h"
#include "tinyxml2.h"
#include "XmlParse.h"
#include "Random.h"
#include "Threshold.h"
#include "State.h"

// TODO REMOVE THIS
#include <iostream>

using namespace tinyxml2;
using namespace domotique::xml;
namespace domotique { namespace process {

void Process::CalculateAll()
{
	_phenomenon->Calculate();
	_controller->Calculate();
	_state->Calculate();
}

std::map<ActorType, double> Process::Values()
{
	return {
		{Phenomenon, _phenomenon->Value()},
		{Controller, _controller->Value()},
		{State, _state->Value()}
	};
}

Process::Process(XMLNode * node)
{
	std::vector<XMLNode *> children;
	for(XMLNode * child = node->FirstChild(); child; child = child->NextSibling())
	{
		children.push_back(child);

	}

	for(XMLNode* child : children)
	{
		//TODO: replace this with a factory
		std::string typestr = child->ToElement()->FindAttribute(XMLMap::AttributeMap[XMLMap::Attributes::Type].c_str())->Value();
		std::cout << typestr <<std::endl;
		//TODO: add error checking to this
		XMLMap::ElementType type = XMLMap::ElementTypeMap.at(typestr.c_str());

		//TODO Enforce phenomenon's declaration before controller ( only for initial dummy Threshold controller)
		switch(type)
		{ 	// TODO: maybe have three actor tags under each process tag
			//			then can loop until controller, phenomenon and state are non null
		case XMLMap::ElementType::Threshold:
			_controller = std::make_shared<actor::controller::Threshold>(new actor::controller::Threshold(child, _phenomenon));
			break;
		case XMLMap::ElementType::Random:
			_phenomenon = std::make_shared<actor::phenomenon::Random>(new domotique::actor::phenomenon::Random(child));
			break;
		case XMLMap::ElementType::State:
			_state.reset(new domotique::actor::State(_phenomenon, _controller, child));
			break;
		case XMLMap::ElementType::None:
		default:
			throw XMLParseException("Type not recognised", __FILE__, __LINE__);
			break;
		};
	}
}

Process::~Process() {
	// TODO Auto-generated destructor stub
}

}}
