#include "userio.h"

int main(int argc, char *argv[])
{
        std::vector<Person*> persons;

        if(argv[1].compare("") == 0)
        {
                consoleUI(&persons);
        }
}
