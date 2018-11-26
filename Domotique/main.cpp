#include <iostream>
#include <map>
#include <exception>

#include "Process.h"
#include "Server.h"
#include "XmlParse.h"
#include "tinyxml2.h"

using namespace domotique;
using namespace tinyxml2;

/*
 * IMPLEMENT TWO MAPPINGS IN EACH LEAF CLASS OF Actor
 * std::map<std::string, XMLMap::Element> _requiredParams;
 * std::map<std::string, XMLMap::Element> _optionalParams;
 * std::map<XMLMap::Element, T> _paramList;
 * Trialling this in Threshold
 * */

int main(int argc, char * argv[])
{
	if(argc < 2) {
		std::cout << "Usage: " << argv[0] << " filename" << std::endl;
		return -1;
	}
	std::string configFileName = argv[1];
	std::cout << "Reading simulation parameters from " << configFileName << std::endl;

	Server monServer = Server();

	monServer.initLog(0);
	monServer.initLog(1);


	monServer.dataLog(12.6, 0);
	monServer.dataLog(98.3, 1);

	XMLDocument config;
	config.LoadFile(configFileName.c_str());
	XMLElement* root = config.RootElement();

	try
	{
		process::Process proc(
				root->FirstChildElement(
						xml::XMLMap::BaseElementMap
						.at(xml::XMLMap::Element::Process)
						.c_str()
				)
				);
		std::cout << "#\tState\tPhen\tControl\n";
		for(int i = 0; i < 10; i++)
		{
			proc.CalculateAll();
			std::cout << i << "\t"
					<< proc.Values()[process::ActorType::State] << "\t"
					<< proc.Values()[process::ActorType::Phenomenon] << "\t"
					<< proc.Values()[process::ActorType::Controller]
					<< std::endl;
		}
	}
	catch (xml::XMLParseException& x)
	{
		std::cout << "XMLParseException caught in " << x.FileName() << ":" << x.LineNo() << "\n\t" << x.what() << std::endl;
		std::cout << "Fatal error, must exit" << std::endl;
		return -1;
	}
	catch (std::exception& e)
	{
		std::cout << "Ex caught: " << e.what();
	}

	return 0;
}
>>>>>>> tiarnach-process
