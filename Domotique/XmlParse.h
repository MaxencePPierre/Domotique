/*
 * \file XmlParse.h
 * \date 19 nov. 2018
 * \author pcoo34
 */

#ifndef DOMOTIQUEXMLPARSE_H_
#define DOMOTIQUEXMLPARSE_H_

#include <map>
#include <string>

namespace domotique{ namespace xml{

class XMLParseException : std::exception
{
private:
	std::string what_message;
	std::string filename;
	int line;
public:
	const char * what()
	{
		return what_message.c_str();
	}
	const char * FileName()
	{
		return filename.c_str();
	}
	const int LineNo()
	{
		return line;
	}
	//XMLParseException(const char * what) : what_message(what) {}
	XMLParseException(const char * what, const char * filename, const int line) : what_message(what), filename(filename), line(line) {}
};

class XMLMap{
public:
	enum class Element
	{
		/* Root element */
		Simulation,
		/* Children */
		Process, Phenomenon, Controller, State,
		/* Parameters for controllers, phenomena and states*/
		InfluencePhenomenon, InfluenceController, ValueLow, ValueHigh, Saturation
	};
	enum class Attributes
	{
		Type, Name
	};

	enum class ElementType
	{
		None, Random, Threshold, State
	};
	static std::map<XMLMap::Element, const std::string> BaseElementMap;
	static std::map<const std::string, Element> ElementMap;

	static std::map<Attributes, const std::string> AttributeMap;

	static std::map<const std::string, ElementType> ElementTypeMap;
//
//	template<typename K, typename V>
//	static K lookupValue(V value, std::map<K,V>);
};

}}

#endif /* XMLPARSE_H_ */
