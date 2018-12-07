/*
 * \file XMLMappings.cpp
 * \date 23 nov. 2018
 * \author pcoo34
 */
#include <map>
#include <string>

#include "XMLMappings.h"
namespace domotique{ namespace xml {

	std::map<XMLMap::Element, const std::string> XMLMap::BaseElementMap = {
			{Element::Simulation	, "simulation"	},
			{Element::Zone 			, "zone"		},
			{Element::Runner 		, "runner"		},
			{Element::Server		, "server"		}
	};
	std::map<const std::string, XMLMap::Element> XMLMap::ElementMap = {
			{"phenomenon"			, Element::Phenomenon		},
			{"controller"			, Element::Controller		},
			{"state"				, Element::State			},
			{"influencePhenomenon"	, Element::InfluencePhenomenon	},
			{"influenceController"	, Element::InfluenceController	},
			{"valueLow"				, Element::ValueLow			},
			{"valueHigh"			, Element::ValueHigh		},
			{"saturation"			, Element::Saturation		},
			{"ticks"				, Element::Ticks			},
			{"VTHRMAX"				, Element::VTHRMAX			},
			{"VTHRMIN"				, Element::VTHRMIN			},
			{"VCTRLMAX"				, Element::VCTRLMAX			},
			{"VCTRLMIN"				, Element::VCTRLMIN			},
			{"SETPT"				, Element::SETPT			},
			{"GAIN"					, Element::GAIN				},
			{"OFFS"					, Element::OFFS				},
			{"AMPL"					, Element::AMPL				},
			{"PHASE"				, Element::PHASE			},
			{"PERIOD"				, Element::PERIOD			},
			{"SAT_MAX"				, Element::SAT_MAX			},
			{"SAT_MIN"				, Element::SAT_MIN			},
	};

	std::map<XMLMap::Attributes, const std::string> XMLMap::AttributeMap = {
			{Attributes::Type		, "type"},
			{Attributes::Name		, "name"}
	};

	std::map<const std::string, XMLMap::ElementType> XMLMap::ElementTypeMap = {
			{"None"					, ElementType::None},
			{"Random"				, ElementType::Random},
			{"Threshold"			, ElementType::Threshold},
			{"State"				, ElementType::State},
			{"OnOff"				, ElementType::OnOff},
			{"Proportional"			, ElementType::Proportional},
			{"Sinusoidal"			, ElementType::Sinusoidal}
	};

}}
