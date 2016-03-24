#include "ConfigProcessor.h"
#include "../commons/exceptions/DappsException.h"
#include <iostream>
#include <fstream>
#include <sstream>

dapps::ConfigProcessor::ConfigProcessor(std::string filename)
{
	if(filename.empty())
	{
		return;
	}
	std::ifstream configFile;
	configFile.open(filename.c_str());
	std::string line;
	if(configFile.is_open())
	{
		std::stringstream buffer;
		buffer << configFile.rdbuf();
		m_config = JSON::parse(buffer.str());
		if(m_config == NULL)
		{
			throw DappsException("could not open config file " + filename);
		}
	} 
	else
	{
		throw DappsException("could not open config file " + filename);
	}
}
