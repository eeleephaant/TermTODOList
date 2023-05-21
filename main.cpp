#include <iostream>
#include "ListManager.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <functional>
#include <vector>

int main(int argc, char* argv[])
{
    ListManager manager;
    manager.parseSettings();
    for (int i = 1; i < argc; i++)
    {

        if (!strcmp(argv[i], "add"))
        {
            std::cout << "Write your TODO: ";
            std::string buffer;
            std::getline(std::cin, buffer);
            manager.addTODO(buffer);
            std::cout << "\n [V] Successfully!";
        }
        else if (!strcmp(argv[i], "remove") || !strcmp(argv[i], "delete") || !strcmp(argv[i], "rem") || !strcmp(argv[i], "del"))
        {
            manager.changeTODOStatus();
        }
        else if (!strcmp(argv[i], "show") || !strcmp(argv[i], "display"))
        {
            manager.displayTODO();
        }
        else if (!strcmp(argv[i], "daily"))
        {
            manager.displayDaily();
        }
        else {
            std::cout << "\n\033[;31m[X]\033[0m Need a command: \n\033[;32m - add \n - remove \n - show\033[0m";
        }
    }
}