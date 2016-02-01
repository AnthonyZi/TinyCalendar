#include "userio.h"

void consoleUI(std::vector<Person*>* pvector)
{
        list(pvector, false, false);
        std::cout << "type 'help' for an overview" << std::endl;

        std::map<std::string, int> ci;
        ci["help"] = 0;
        ci["new"] = 10;
        ci["delete"] = 11;
        ci["edit"] = 12;
        ci["listall"] = 20;
        ci["shownext"] = 21;
        ci["load"] = 30;
        ci["save"] = 31;
        ci["exit"] = 40;

        while(1)
        {
                std::string command;
                command = getCommand();

                switch(ci.find(command)->second)
                {
                case 0:
                        printhelp();
                        break;
                case 10:
                        addPerson(pvector);
                        break;
                case 11:
                        delPerson(pvector);
                        break;
                case 12:
                        editPerson(pvector);
                        break;
                case 20:
                        list(pvector);
                        break;
                case 21:
                        list(pvector, false, false);
                        break;
                case 30:
                        load(pvector);
                        break;
                case 31:
                        save(pvector);
                        break;
                case 40:
                        exit(0);
                        break;
                default:
                        std::cout << "command not found" << std::endl;
                        break;
                }

/*
                if(command.compare("new") == 0)
                        addPerson(pvector);

                if(command.compare("delete") == 0)
                        delPerson(pvector);
                
                if(command.compare("listall") == 0)
                        list(pvector);

                if(command.compare("shownext") == 0)
                        list(pvector, false, false);
                
                if(command.compare("exit") == 0)
                        exit(0);

                if(command.compare("load") == 0)
                        load(pvector);

                if(command.compare("save") == 0)
                        save(pvector);

                if(command.compare("help") == 0)
                        helptext();

                if(command.compare("edit") == 0)
                        editPerson();
*/
        }
}

std::string getCommand()
{
        std::string input;
        std::cin >> input;
        system("clear");
        return input;
}

void addPerson(std::vector<Person*>* pvector)
{
        Person* newPerson = new Person();
        
        std::string input;
        int int1, int2, int3;

        std::cout << "Name: ";
        std::cin >> input;
        newPerson->setName(input);

        std::cout << "First Name: ";
        std::cin >> input;
        newPerson->setFirstName(input);

        std::cout << "Second Name [type '-' if you want to leave that empty]: ";
        std::cin >> input;
        if(input.compare("-") == 0)
                input = "";
        newPerson->setSecondName(input);

        std::cout << "Birthdate: ";
        std::cout << "day: ";
        std::cin >> int1;
        std::cout << "month: ";
        std::cin >> int2;
        std::cout << "year: ";
        std::cin >> int3;
        newPerson->setDate(int3, int2, int1);

        std::cout << "Extra Information [type '-' if you want to leave that empty]: ";
        std::cin >> input;
        if(input.compare("-") == 0)
                input = "";
        newPerson->setPersonalID(input);

        pvector->push_back(newPerson);

        list(pvector, true);
}

void delPerson(std::vector<Person*>* pvector)
{
        int id;

        list(pvector, true, true, true);
        std::cout << std::endl << "type the ID of the one you want to delete" << std::endl;
        std::cin >> id;
        pvector->erase(pvector->begin()+id);

        list(pvector, true);
}

void editPerson(std::vector<Person*>* pvector)
{
        int id;
        std::string input;
        
        list(pvector, true, true, true);
        std::cout << std::endl << "type the ID of the one you want to edit" << std::endl;
        std::cin >> id;
        std::cout << "Name: [" << (*pvector)[id]->getName() << "] -> ";
        std::cin >> input;
        (*pvector)[id]->setName(input);

        std::cout << "First Name: [" << (*pvector)[id]->getFirstName() << "] -> ";
        std::cin >> input;
        (*pvector)[id]->setFirstName(input);

        std::cout << "Second Name: [" << (*pvector)[id]->getSecondName() << "] -> ";
        std::cin >> input;
        if(input.compare("-") == 0)
                input = "";
        (*pvector)[id]->setSecondName(input);

        int int1, int2, int3;
        std::cout << "Birthdate: ";
        std::cout << "day: [" << (*pvector)[id]->getDate()->tm_mday << "] -> ";
        std::cin >> int1;
        std::cout << "month: [" << (*pvector)[id]->getDate()->tm_mon << "] -> ";
        std::cin >> int2;
        std::cout << "year: [" << (*pvector)[id]->getDate()->tm_year << "] -> ";
        std::cin >> int3;
        (*pvector)[id]->setDate(int3, int2, int1);

        std::cout << "Extra Information [" << (*pvector)[id]->getPersonalID() << "] -> ";
        std::cin >> input;
        if(input.compare("-") == 0)
                input = "";
        (*pvector)[id]->setPersonalID(input);

        list(pvector, true);
}

void list(std::vector<Person*>* pvector, bool nameSort ,bool all, bool withID)
{
        system("clear");
        if(nameSort)
                sortPersons(pvector, 0);
        else
                sortPersons(pvector, 1);

        int lastperson;
        int firstperson = 0;
        if(all)
                lastperson = pvector->size();
        else
        {
                lastperson = 0;
                time_t now;
                struct tm compare;
                time(&now);
                
                while(1)
                {
                        if(pvector->size()-1 == (unsigned int)lastperson)
                                break;
                        compare = *(localtime(&now));
                        compare.tm_mday = (*pvector)[lastperson]->getDate()->tm_mday;
                        compare.tm_mon = (*pvector)[lastperson]->getDate()->tm_mon;

                        if(difftime(mktime(&compare), now) < 0)
                                firstperson++;

                        if(difftime(mktime(&compare), now) < 2592000)
                                lastperson++;
                        else
                                break;
                }
        }
        for(int i = firstperson; i < lastperson; i++)
        {
                if(withID)
                        std::cout << "[" << i << "] ";
                std::cout << *((*pvector)[i]);
        }
        std::cout << std::endl;
}

void load(std::vector<Person*>* pvector)
{
        std::string input;
        std::cout << "filename: ";
        std::cin >> input;
        
        if(readFile(input, pvector))
                list(pvector, true);
}

void save(std::vector<Person*>* pvector)
{
        std::string input;
        std::cout << "filename [type '-' for standard-file /home/zmann/windowreminder]: ";
        std::cin >> input;

        if(input.compare("-") == 0)
                input = "/home/zmann/.windowreminder";

        writeFile(pvector, input);
        
        list(pvector, true);
}

void printhelp()
{
        std::cout << "help: print this help" << std::endl;
        std::cout << std::endl;

        std::cout << "new: create a new entry" << std::endl;
        std::cout << "delete: delete an entry" << std::endl;
        std::cout << "edit: edit an existing entry" << std::endl;
        std::cout << std::endl;
        
        std::cout << "listall: print all entries sorted by name" << std::endl;
        std::cout << "shownext: print the entries that have a matching birthdate withhin the next 30 days" << std::endl;
        std::cout << std::endl;

        std::cout << "load: load a file" << std::endl;
        std::cout << "save: save entries" << std::endl;
        std::cout << std::endl;

        std::cout << "exit: quit programm" << std::endl;
}
