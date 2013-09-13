#include "JsonFile.h"
#include <json/json.h>
#include "core/ResourceManager.h"
#include <iostream>
#include <fstream>
#include <list>

JsonFile::JsonFile(const char * filePath)
{
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful;
    std::string jsonFile;
    
    jsonFile.append(ResourceManager::getAssetsFolderPath());
    jsonFile.append(filePath);
    
    // This is very important, use ifstream, not a string!!!!
    std::ifstream jsonStream(jsonFile.c_str(), std::ifstream::binary);
    
    parsingSuccessful = reader.parse(jsonStream, root, false);
    
    if (parsingSuccessful == false)
    {
        std::cout << "Failed to parse file " << jsonFile << std::endl 
                << reader.getFormatedErrorMessages() << std::endl;
    }
    
    std::string encoding = root.get("encoding", "UTF-8").asString();
    
    const Json::Value plugins = root["plug-ins"];
    std::list<std::string> pluginsList;
    
    for (int index = 0; index < plugins.size(); ++index)
    {
        pluginsList.push_back(plugins[index].asString());
    }
    
    int indent = root["indent"].get("length", 3).asInt();
    bool useSpace = root["indent"].get("use_space", true).asBool();
    
    // Print the results
    std::cout << "Encoding: " << encoding << std::endl;
    std::cout << "Plug-ins: " << std::endl;
    
    for (std::list<std::string>::iterator currentPlugin = pluginsList.begin(); currentPlugin != pluginsList.end(); ++currentPlugin)
    {
        std::cout << "  " << * currentPlugin << std::endl;
    }
    
    // Now we save new values to the file
}

JsonFile::~JsonFile()
{
	
}