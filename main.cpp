#include "userio.h"
#include <vector>
#include "person.h"
#include <iostream>

int main(int argc, char *argv[])
{
        std::cout << "--TinyCal--" << std::endl;
        std::vector<Person*> persons;

        if(argc == 1)
        {
                system("clear");
                consoleUI(&persons);
        }
        else
        {
                std::string param(argv[1]);
                if(param.compare("list") == 0)
                        list(&persons);
        }
}
