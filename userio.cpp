#include "userio.h"

void consoleUI(std::vector<Person*>* pvector)
{
        std::cout << "type 'help' for an overview" << std::endl;
        while(1)
        {
                std::string command;
                command = getCommand();

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
        }
}

std::string getCommand()
{
        std::string input;
        std::cin >> input;
        system("clear");
        return input;
}

void addPerson(std::vector<Person*>* pvector, bool console)
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

        if(console)
                list(pvector, true);
}

void delPerson(std::vector<Person*>* pvector, bool console)
{
        int id;

        list(pvector, true, true, true);
        std::cout << std::endl << "type the ID of the one you want to delete" << std::endl;
        std::cin >> id;
        pvector->erase(pvector->begin()+id);

        if(console)
                list(pvector, true);
}

bool nameCompare(Person* p1, Person* p2)
{
        if(p1->getName().compare(p2->getName()) < 0)
                return true;
        return false;
}

bool dateCompare(Person* p1, Person* p2)
{
        struct tm c1, c2;
        time_t now;
        time(&now);
 
        c1 = *(localtime(&now));
        c2 = *(localtime(&now));

        c1.tm_mday = p1->getDate()->tm_mday;
        c1.tm_mon = p1->getDate()->tm_mon;
        c2.tm_mday = p2->getDate()->tm_mday;
        c2.tm_mon = p2->getDate()->tm_mon;

        if(difftime(mktime(&c1), mktime(&c2)) < 0)
                return true;
        return false;
}

void list(std::vector<Person*>* pvector, bool nameSort ,bool all, bool withID, bool console)
{
        if(console)
                system("clear");
        if(nameSort)
                std::sort(pvector->begin(), pvector->end(), nameCompare);
        else
                std::sort(pvector->begin(), pvector->end(), dateCompare);


        int lastperson;
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

                        if(difftime(mktime(&compare), now) < 2592000)
                                lastperson++;
                        else
                                break;
                }
        }
        for(int i = 0; i < lastperson; i++)
        {
                if(withID)
                        std::cout << "[" << i << "] ";
                std::cout << *((*pvector)[i]);
        }
        std::cout << std::endl;
}

void load(std::vector<Person*>* pvector, bool console)
{
        std::string input;
        std::cout << "filename: ";
        std::cin >> input;
        
        if(readFile(input, pvector))
                list(pvector, true);
}

void save(std::vector<Person*>* pvector, bool console)
{
        std::string input;
        std::cout << "filename: ";
        std::cin >> input;

        writeFile(pvector, input);
        
        if(console)
                list(pvector, true);
}
