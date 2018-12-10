/*
 * \file Controller.h
 *
 * \date 12 Nov 2018
 * \author pcoo34
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <memory>

#include "Actor.h"
#include "tinyxml2.h"
#include <memory>

namespace domotique {
namespace actor {
class State;
/**
 * \brief Base class for all Controllers
 * */
class Controller: public Actor
{
	protected:
		std::shared_ptr< State > _state;
	public:
		void registerState(std::shared_ptr< State > const& s)
		{
			_state = s;
		}
		static std::shared_ptr< Controller > makeController(tinyxml2::XMLNode * node);
};

}
}

#endif /* CONTROLLER_H_ */
