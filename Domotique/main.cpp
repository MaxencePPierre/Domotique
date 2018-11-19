#include <iostream>
#include <map>
#include <exception>

#include "Process.h"
#include "Random.h"
#include "Threshold.h"
#include "State.h"

#include "tinyxml2.h"

using namespace domotique;
using namespace tinyxml2;
//
//void visitNode(tinyxml2::XMLNode* node, int depth)
//{
//    if(dynamic_cast<const tinyxml2::XMLComment *>(node))
//        return;
//    for(int i = 0;i<depth;i++)
//        std::cout << " ";
//    std::cout << depth << " " << node->Value() << (node->NoChildren()? "\tLEAF":"") << std::endl;
////  if(node->NoChildren())
////  {
////      cout << "L";
////  }
//    for(tinyxml2::XMLNode * child = node->FirstChildElement(); child; child = child->NextSibling())
//    {
//        visitNode(child, depth+1);
//    }
//}
//
//enum Element
//{
//	/* Root element */
//	Simulation,
//	/* Children */
//	Process, Phenomenon, Controller,
//	/* Parameters for controllers and phenomena */
//	Influence, ValueLow, ValueHigh, Saturation
//};
//enum ElementType
//{
//	Random, Threshold
//};
//enum Attributes
//{
//	Type, Name
//};
//const std::map<Element, std::string> ElementMap = {
//		{Simulation	, "simulation"},
//		{Process	, "process"},
//		{Phenomenon	, "phenomenon"},
//		{Controller	, "controller"},
//		{Influence	, "influence"},
//		{ValueLow	, "valueLow"},
//		{ValueHigh	, "valueHigh"},
//		{Saturation	, "saturation"}
//};
////std::map<ElementType, const char *> ElementTypeMap = {
////		{Random : "random"},
////		{Threshold : "threshold"}
////};
//std::map<const char *, ElementType> ElementTypeMap = {
//		{"random"	, Random},
//		{"threshold", Threshold}
//};
//std::map<Attributes, const char *> AttributeMap = {
//		{Type	, "type"},
//		{Name	, "name"}
//};
//
//class XMLParseException : std::exception
//{
//private:
//	std::string what_message;
//public:
//	const char * what()
//	{
//		return what_message.c_str();
//	}
//	XMLParseException(const char * what) :what_message(what) {}
//};
//template<typename KEY, typename T>
//class Factory
//{
//private:
//	typedef T *(*ObjectCreator)();
//	static std::map<KEY, ObjectCreator> _ObjectCreatorMap;
//
//	/**
//	 * \param CLASS_T type of class to create
//	 * \return new object of the given type CLASS_T
//	 */
//	template<typename CLASS_T>
//	static T* createObject() { return new CLASS_T(); }
//public:
//	template<typename CLASS_T>
//	static void registerAType(KEY key)
//	{
//		if(_ObjectCreatorMap.find(key) != _ObjectCreatorMap.end())
//			std::cerr << "Type already in map\n";
//		// TODO: add actual error handling above
//		_ObjectCreatorMap.insert( std::make_pair<KEY, ObjectCreator>(key, &createObject<CLASS_T>));
//	}
//
//	/** \return true if type corresponding to id already in _ObjectCreatorMap */
//	static bool hasClassAlready(KEY key)
//	{
//		return _ObjectCreatorMap.find(key) != _ObjectCreatorMap.end();
//	}
//	static T * createObject(KEY key)
//	{
//		typename std::map<KEY, ObjectCreator>::iterator i;
//		i = _ObjectCreatorMap.find(key);
//		if (i == _ObjectCreatorMap.end()) return NULL;
//		return ((*i).second)();
//	}
//};
//
//process::Process ConstructProcess(XMLNode * root)
//{
//	actor::Phenomenon* phen;
//	actor::Controller* cont;
//	actor::State* state;
//
//	XMLNode * processNode = root->FirstChildElement(ElementMap.at(Element::Process).c_str());
//	if(!processNode) throw XMLParseException("Could not find process element");
//	std::cout << "Found process node called " << processNode->Value() << std::endl;
//	XMLNode * phenomenon = processNode->FirstChildElement(ElementMap.at(Element::Phenomenon).c_str());
//	if(!phenomenon) throw XMLParseException("Could not find phenomenon");
//	std::cout << "Found phenomenon\n" ;
//	const XMLAttribute * phenomenonType = phenomenon->ToElement()->FindAttribute(AttributeMap[Type]);
//	if(!phenomenonType) throw XMLParseException("Could not find phenomenon type");
////	std::cout << "Phenomenon type: " << (ElementTypeMap[phenomenonType->Value()]) << std::endl;
//
//	XMLNode *node;
//	switch(ElementTypeMap[phenomenonType->Value()])
//	{
//	case ElementType::Random:
//		node = phenomenon->FirstChildElement(ElementMap.at(Element::Influence));
//		phen = new actor::phenomenon::Random(0.00001, -10, 10);
//		break;
//	}
//
//	actor::phenomenon::Random p = actor::phenomenon::Random(0.00001, -10, 10);
//	actor::controller::Threshold c = actor::controller::Threshold(0.9, 5, phen);
//	actor::State s = actor::State(phen, cont);
//
//	process::Process proc = process::Process(phen, state, cont);
//	return proc;
//}

int main(int argc, char * argv[])
{
	if(argc < 2) {
		std::cout << "Usage: " << argv[0] << " filename" << std::endl;
		return -1;
	}
	std::string configFileName = argv[1];
	std::cout << "Reading simulation parameters from " << configFileName << std::endl;

//	(Factory<actor::controller::Threshold, actor::Actor>).registerAType<actor::controller::Threshold>(4);
//	Factory<actor::controller::Threshold, actor::Actor>.registerAType<actor::controller::Threshold>(1);
//	registerAType<actor::phenomenon::Random>(2);


	XMLDocument config;
	config.LoadFile(configFileName.c_str());
	XMLElement* root = config.RootElement();


//	process::Process proc = ConstructProcess(root);
//
//	for(int i = 0; i < 100; i++)
//	{
//		proc.CalculateAll();
//		std::cout << i << "\t"
//				<< proc.Values()[process::ActorType::State] << "\t"
//				<< proc.Values()[process::ActorType::Phenomenon] << "\t"
//				<< proc.Values()[process::ActorType::Controller]
//				<< std::endl;
//	}

	return 0;
}
