/*
 * \file Process.h
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#ifndef PROCESS_H_
#define PROCESS_H_

#include <map>
#include <memory>

#include "tinyxml2.h"

#include "Phenomenon.h"
#include "Controller.h"
#include "State.h"

namespace domotique { namespace process {

/**
 * \brief Serves as index for the map returned from a call to Process::Values()
 * */
enum ActorType { Phenomenon, Controller, State };

/**
 * \brief The triplet of actors that make up one simulation environment.
 *
 * A process contains one Phenomenon subclass, one Controller subclass, and one State subclass.
 * It ensures that their Calculate() functions are called in the correct order.
 * This class does not implement XMLParseable as we couldn't figure out a way to create and return a type based on a map.
 * */
class Process {
private:
	std::shared_ptr<actor::Phenomenon> _phenomenon;
	std::shared_ptr<actor::Controller> _controller;
	std::unique_ptr<actor::State> _state;
	std::string name;

public:
	/**
	 * \brief Calls Actor::Calculate()-derived methods of associated Phenomenon, Controller and State classes.
	 * */
	void CalculateAll();
	/**
	 * \brief Mechanism to return values to the scope where the process is declared, where they can be acted on
	 *
	 * \return Map that contains strictly one value corresponding to each actor subclass' value. Indexed using the ActorType enumeration.
	 */
	std::map<ActorType, double> Values();
	/**
	 * \brief Constructor that parses the xml dom descending from the node given.
	 *
	 * \param node Pointer to an xml tree that represents a complete process as defined in the description of this Process class.
	 *
	 * \throws XMLParseException if an xml child element has a type that is neither a derivative of Phenomenon or Controller, nor State.
	 * */
	Process(tinyxml2::XMLNode *node);
	virtual ~Process();
};

}}

#endif /* PROCESS_H_ */
