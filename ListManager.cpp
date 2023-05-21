#include "ListManager.h"

void ListManager::parseSettings()
{
    std::string pathToSettings = "./settings.ini";
    std::ifstream settings;
    settings.open(pathToSettings);
    std::string buffer;
    getline(settings, buffer);
    this->pathToList = buffer;
}

void ListManager::writeTODO(std::string line)
{
    std::ofstream listFile;
    listFile.open(this->pathToList, std::ios::app);
    if (listFile.is_open())
    {
        listFile << line << std::endl;
    }
    listFile.close();
}



std::vector<std::string> ListManager::readTODO()
{
    std::ifstream listFile;
    std::vector<std::string> output;
    listFile.open(this->pathToList);
    if (listFile.is_open())
    {
        std::string buffer;
        while (getline(listFile, buffer))
        {
            output.push_back(buffer);
        }
    }
    else {
        perror("not opened");
    }
    return output;
}


void ListManager::addTODO(std::string todoLine)
{
    std::ofstream fileList;
    fileList.open(this->pathToList, std::ios::app);
    fileList << "[...]" << todoLine << "\n";
    fileList.close();
}

void ListManager::changeTODOStatus()
{
    std::vector<std::string> fileContains = readTODO();
    for (int i = 0; i < fileContains.size(); i++)
    {
        std::cout << i + 1 << ") " << fileContains.at(i) << std::endl;
    }
    int line;
    std::cout << "Choose line (0 for delete all TODOs marked as completed) :";
    std::cin >> line;
    
    line = line - 1;
    if (fileContains.at(line).find("[...]") != std::string::npos)
    {
        fileContains.at(line).replace(0, 5, "[V]");
    }
    std::ofstream fileList;
    fileList.open(this->pathToList, std::ios::trunc);
    for (int i = 0; i < fileContains.size(); i++)
    {
        if (fileContains.at(i) != "") fileList << fileContains.at(i) << "\n";
    }
    fileList.close();
}

void ListManager::displayTODO()
{
    std::vector<std::string> contains = readTODO();
    for (int i = 0; i < contains.size(); i++)
    {
        std::cout << contains.at(i) << std::endl;
    }
}

void ListManager::displayDaily()
{
    
}
