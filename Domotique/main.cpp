#include <iostream>
#include <map>
#include <exception>

#include "Runner.h"
#include "Server.h"
#include "tinyxml2.h"
#include "XMLMappings.h"

using namespace domotique;
using namespace tinyxml2;

int main(int argc, char * argv[])
{
	if( argc < 2 )
	{
		std::cout << "Usage: " << argv[0] << " xml-configuration-file-name" << std::endl;
		return -1;
	}
	std::string configFileName = argv[1];
	std::cout << "Reading simulation parameters from `" << configFileName << '\'' << std::endl;

	try
	{
		runner::Runner r( configFileName );
		r.run();
	} catch( xml::XMLParseException& x )
	{
		std::cerr << "XMLParseException caught in " << x.FileName() << ":" << x.LineNo() << "\n\t" << x.what() << std::endl;
		std::cerr << "Fatal error, must exit" << std::endl;
		return -1;
	}
//	catch( std::out_of_range& e )
//	{
//		std::cerr << "out_of_range exception : " << e.what() << std::endl;
//	} catch( std::exception& e )
//	{
//		std::cerr << "Ex caught: " << e.what();
//		return -1;
//	}
	std::cout << "Application exiting" << std::endl;

	return 0;
}
