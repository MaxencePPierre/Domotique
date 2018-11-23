#include <map>
#include <string>
#include "XmlParse.h"
namespace domotique{ namespace xml {

	std::map<XMLMap::Element, const std::string> XMLMap::ElementMap = {
			{Element::Simulation	, "simulation"},
			{Element::Process		, "process"},
			{Element::Phenomenon	, "phenomenon"},
			{Element::Controller	, "controller"},
			{Element::State			, "state"},
			{Element::Influence		, "influence"},
			{Element::ValueLow		, "valueLow"},
			{Element::ValueHigh		, "valueHigh"},
			{Element::Saturation	, "saturation"}
	};

	std::map<XMLMap::Attributes, const std::string> XMLMap::AttributeMap = {
			{Attributes::Type	, "type"},
			{Attributes::Name	, "name"}
	};

	std::map<const std::string, XMLMap::ElementType> XMLMap::ElementTypeMap = {
			{"None"		, ElementType::None},
			{"Random"	, ElementType::Random},
			{"Threshold", ElementType::Threshold},
			{"State"	, ElementType::State}
	};

//template<typename K, typename V>
//K XMLMap::lookupValue(V value, std::map<K, V> map)
//{
//	for (auto it = map.begin(); it != map.end(); ++it)
//	{
//	if (it->second == value)
//	{
//		return it->first;
//	}
//	}
//}
}}
