/*
 * \file XmlParse.h
 * \date 19 nov. 2018
 * \author pcoo34
 */

#ifndef XMLMAPPINGS_H_
#define XMLMAPPINGS_H_

#include <exception>
#include <map>
#include <string>

namespace domotique{ namespace xml{

/**
 * \brief General exception thrown when there is some error in parsing an xml file.
 * */
class XMLParseException : std::exception
{
private:
	// TODO change this string to an sstream, do the conversions in this class, in constructor?
	std::string what_message;
	std::string filename;
	int line;
public:
	/// Readonly character pointer to message that should be printed when exception caught
	const char * what()
	{
		return what_message.c_str();
	}
	/// File where exception was thrown
	const char * FileName()
	{
		return filename.c_str();
	}
	/// Line in file from where exception was thrown.
	const int LineNo()
	{
		return line;
	}
	/**
	 * \brief Assigns passed parameters to private member variables
	 *
	 * \param what Readonly character pointer to message that should be printed when exception caught
	 * \param filename Name of file from where exception was thrown. As returned from the gcc \c __FILE__ macro.
	 * \param line Line in file from where exception was thrown. As returned from the gcc \c __LINE__ macro.
	 *
	 * 		\note The \c filename and \c line parameters have proved less useful than planned as the majority of cases of XMLParseException being thrown arise in the XMLParseable class and hence this parameter invariably has the value «\c XMLParseable.cpp».
	 * */
	XMLParseException(const char * what, const char * filename, const int line) : what_message(what), filename(filename), line(line) {}
};

/**
 * \brief Enumerations and maps to aid parsing of xml files
 *
 * Maps are used rather than big string arrays to replace comparisons and branching with lookups, which are nicer to code and extend.
 * */
class XMLMap{
public:
	/// XML elements (i.e. tag names)
	enum class Element
	{
		/* Root element */
		Simulation,
		/* Children */
		Zone, Runner,
		/* Grandchildren */
		Phenomenon, Controller, State,
		/* Parameters for controllers, phenomena and states*/
		InfluencePhenomenon, InfluenceController, ValueLow, ValueHigh, Saturation,
		VTHRMAX, VTHRMIN, VCTRLMAX, VCTRLMIN, // OnOff
		/* Parameters for the control classes of Server and Runner */
		Ticks
	};
	/** \brief The attributes allowed in each tag
	 * \note The presence of these attributes is selectively enforced. Insertion of one of these is no guarantee of it being parsed.
	 */
	enum class Attributes
	{
		Type, Name
	};
	/// The allowed values of the \c Attributes::Type attribute: subclasses of Phenomenon and Controller, along with the State class.
	enum class ElementType
	{
		None, Random, Threshold, State
	};
	/// Map relating a given XML element to its string representation, contains only the root element Element::Simulation and its direct descendants
	static std::map<XMLMap::Element, const std::string> BaseElementMap;
	/// Map relating a given string name of an element to its XMLMap::Element value
	static std::map<const std::string, Element> ElementMap;
	/// Map relating a given XML attribute to its string representation
	static std::map<Attributes, const std::string> AttributeMap;
	/// Map relating strings to xml element types.
	static std::map<const std::string, ElementType> ElementTypeMap;
//	Probably better to just use two maps
//	template<typename K, typename V>
//	static K lookupKeyByValue(V value, std::map<K,V>);
};

}}

#endif /* XMLPARSE_H_ */
