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
	XMLNode * controller, * phenomenon, * state;
	controller	= node->FirstChildElement(xml::XMLMap::ElementMap.at(XMLMap::Element::Controller).c_str());
	phenomenon	= node->FirstChildElement(xml::XMLMap::ElementMap.at(XMLMap::Element::Phenomenon).c_str());
	state		= node->FirstChildElement(xml::XMLMap::ElementMap.at(XMLMap::Element::State).c_str());
	if(!(controller || phenomenon || state))
	{
		std::ostringstream s;
		s	<< "Missing elements from process : ";
		if(!controller) s << XMLMap::ElementMap.at(XMLMap::Element::Controller) << " ";
		if(!phenomenon)	s << XMLMap::ElementMap.at(XMLMap::Element::Phenomenon) << " ";
		if(!state) 		s << XMLMap::ElementMap.at(XMLMap::Element::State);
		s	<< "\n";
		throw XMLParseException(s.str().c_str(), __FILE__, __LINE__);
	}

	XMLNode* children[] = {phenomenon, controller, state};
	const unsigned N_CHILDREN = 3;
	for(unsigned i = 0; i < N_CHILDREN; i++)
	{
		//TODO: replace this with a factory
		std::string typestr = children[i]->ToElement()->FindAttribute(XMLMap::AttributeMap[XMLMap::Attributes::Type].c_str())->Value();

		//TODO: add error checking to this
		XMLMap::ElementType type = XMLMap::ElementTypeMap.at(typestr.c_str());

		//TODO Implement phenomenon first, then on to controller
		switch(type)
		{ 	// TODO: maybe have three actor tags under each process tag
			//			then can loop until controller, phenomenon and state are non null
		case XMLMap::ElementType::Threshold:
//			try{
			std::cout << "Getting ready to create Threshold\n";
			_controller = new domotique::actor::controller::Threshold(controller, _phenomenon);
			std::cout << "Created Threshold controller\n";
//			}
//			catch (XMLParseException& e)
//			{
//				std::cout << e.what();
//			}
			break;
		case XMLMap::ElementType::Random:
			_phenomenon = new domotique::actor::phenomenon::Random(phenomenon);
			std::cout << "Created Random phenomenon\n";
			break;
		case XMLMap::ElementType::State:
			_state		= new domotique::actor::State(_phenomenon, _controller, state);
			std::cout << "Created State\n";
			break;
		case XMLMap::ElementType::None:
		default:
			throw new XMLParseException("Type not recognised", __FILE__, __LINE__);
			break;
		};
	}
}

Process::Process(actor::Phenomenon* phenomeonon, actor::State* state, actor::Controller* controller)
: _phenomenon(phenomeonon), _state(state), _controller(controller) {
	// TODO Auto-generated constructor stub

}

Process::~Process() {
	// TODO Auto-generated destructor stub
}

}}
