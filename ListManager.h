#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <regex>



class ListManager
{
private:
    std::string pathToList;

public:
    void parseSettings();
    void writeTODO(std::string line);
    void changeTODOStatus();
    void addTODO(std::string todoLine);
    void displayTODO();
    void displayDaily();
    std::vector<std::string> readTODO();
};