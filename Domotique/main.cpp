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

void visitNode(tinyxml2::XMLNode* node, int depth)
{
    if(dynamic_cast<const tinyxml2::XMLComment *>(node))
        return;
    for(int i = 0;i<depth;i++)
        std::cout << " ";
    std::cout << depth << " " << node->Value() << (node->NoChildren()? "\tLEAF":"") << std::endl;
//  if(node->NoChildren())
//  {
//      cout << "L";
//  }
    for(tinyxml2::XMLNode * child = node->FirstChildElement(); child; child = child->NextSibling())
    {
        visitNode(child, depth+1);
    }
}

enum Element
{
	Simulation, Process, Phenomenon, Controller
};
enum ElementType
{
	Random, Threshold
};
enum Attributes
{
	Type, Name
};
const std::map<Element, char *> ElementMap = {
		{Simulation	, "simulation"},
		{Process	, "process"},
		{Phenomenon	, "phenomenon"},
		{Controller	, "controller"}
};
//std::map<ElementType, const char *> ElementTypeMap = {
//		{Random : "random"},
//		{Threshold : "threshold"}
//};
const std::map<const char *, ElementType> ElementTypeMap = {
		{"random"	, Random},
		{"threshold", Threshold}
};
std::map<Attributes, const char *> AttributeMap = {
		{Type	, "type"},
		{Name	, "name"}
};

class XMLParseException : std::exception
{
private:
	std::string what_message;
public:
	const char * what()
	{
		return what_message.c_str();
	}
	XMLParseException(const char * what) :what_message(what) {}
};

process::Process ConstructProcess(XMLNode * root)
{
	std::cout << "the\n";
	XMLNode * processNode = root->FirstChildElement(ElementMap.at(Element::Process));
	std::cout << "last\n";
	if(!processNode) throw XMLParseException("Could not find process element");
	std::cout << "thing\n";
	std::cout << "Found process node called " << processNode->Value() << std::endl;
	XMLNode * phenomenon = processNode->FirstChildElement(ElementMap.at(Element::Phenomenon));
	if(!phenomenon) throw XMLParseException("Could not find phenomenon");
	std::cout << "Found phenomenon\n" ;
	const XMLAttribute * phenomenonType = phenomenon->ToElement()->FindAttribute(AttributeMap[Type]);
	if(!phenomenonType) throw XMLParseException("Could not find phenomenon type");
	std::cout << "Phenomenon type: " << ElementMap.at(Element::Phenomenon) << std::endl;

	actor::phenomenon::Random p = actor::phenomenon::Random(0.00001, -10, 10);
	actor::phenomenon::Random& phen = p;
	actor::controller::Threshold c = actor::controller::Threshold(0.9, 5, phen);
	actor::controller::Threshold& cont = c;
	actor::State s = actor::State(phen, cont);
	actor::State& state = s;

	process::Process proc = process::Process(phen, state, cont);
	return proc;
}

int main(int argc, char * argv[])
{
	if(argc < 2) return -1;
	std::string configFileName = argv[1];
	std::cout << "Reading simulation parameters from " << configFileName << std::endl;

	XMLDocument config;
	config.LoadFile(configFileName.c_str());
	std::cout << "Root\n";
	std::cout << config.RootElement()->Value() << '\n';
	XMLElement* root = config.RootElement();
	std::cout << "Root: " << root->Value() << std::endl;
	process::Process proc = ConstructProcess(root);
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
