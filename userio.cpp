void consoleUI(std::vector<Person*>* pvector)
{
        while(1)
        {
                std::string command;
                command = getCommand();

                if(command.compare("new")
                        addUser(pvector);

                if(command.compare("delete")
                        delUser(pvector);
                
                if(command.compare("listall")
                        list(pvector);

                if(command.compare("shownext")
                {
                        list(pvector, false, false);
                }
        }
}

std::string getCommand()
{
        std::string input;
        std::cin >> input;
        return input;
}

void addUser(std::vector<Person*>* pvector)
{
        Person* newPerson = new Person();
        
        std::string input;
        int int1, int2, int3;

        std::cout << "Name:" << std::endl;
        std::cin >> input;
        newPerson->setName(input);

        std::cout << "First Name:" << std::endl;
        std::cin >> input;
        newPerson->setFirstName(input);

        std::cout << "Second Name: [leave empty if you want]" << std::endl;
        std::cin >> input;
        newPerson->setSecondName(input);

        std::cout << "Birthdate:" << std::endl;
        std::cout << "day: ";
        std::cin >> int1;
        std::cout << std::endl;
        std::cout << "month: ";
        std::cin >> int2;
        std::cout << std::endl;
        std::cout << "year: ";
        std::cin >> int3;
        std::cout << std::endl;
        newPerson->setDate(int3, int2, int1)

        std::cout << "Extra Information:" << std::endl;
        std::cin >> input;
        newPerson->setPersonalID(input);

        pvector->push_back(newPerson);
}

void delUser(std::vector<Person*>* pvector)
{
        int id;

        list(pvector, true, true, true);
        std::cin >> id;
        pvector->erase(pvector->begin()+id);
}

bool nameCompare(Person* p1, Person* p2)
{
        if(p1->getName().compare(p2.getName()) < 0)
                return true;
        return false;
}

bool dateCompare(Person* p1, Person* p2)
{
        if(difftime(mktime(&(p1->getDate())), mktime(&(p2->getDate()))) < 0)
                return true;
        return false;
}

void list(std::vector<Person*>* pvector, bool nameSort ,bool all, bool withID)
{
        if(nameSort)
                std::sort(pvector->begin(), pvector->end(), nameCompare);
        else
                std::sort(pvector->begin(), pvector->end(), dateCompare);


        int lastperson;
        if(all)
                pvector->length();
        else
        {
                int lastperson = 0;
                time_t now;
                time(&now);
                
                while(difftime(mktime(&(pvector[lastperson]->getDate())), now) < 2592000)
                        lastperson++;
        }
        for(int i = 0; i < lastperson; i++)
        {
                if(withID)
                        std::cout << "[" << i << "] ";
                std::cout << pvector[i] << std::endl;
        }
}
