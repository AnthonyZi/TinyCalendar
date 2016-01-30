#include "fileio.h"

bool readFile(std::string pfilename, std::vector<Person*>* pvector)
{
        pvector->erase(pvector->begin(), pvector->end());
        std::fstream fs;
        fs.open(pfilename.c_str(), std::fstream::in);

        if(!fs)
        {
                std::cout << "error while opening " << pfilename << std::endl;
                return false;
        }

        std::string input;
        Person* newPerson;

        while(!fs.eof())
        {
                std::getline(fs, input);
                if(input.substr(0,5).compare("BEGIN") == 0)
                        newPerson = new Person();
                if(newPerson)
                {
                        if(input.substr(0,3).compare("END") == 0)
                                pvector->push_back(newPerson);

                        if(input.substr(0,4).compare("NAME") == 0)
                                newPerson->setName(input.substr(5));

                        if(input.substr(0,9).compare("FIRSTNAME") == 0)
                                newPerson->setFirstName(input.substr(10));
                        
                        if(input.substr(0,10).compare("SECONDNAME") == 0)
                                newPerson->setSecondName(input.substr(11));

                        if(input.substr(0,9).compare("BIRTHDATE") == 0)
                        {
                                std::size_t posDay = input.find(":");
                                std::size_t posMon = input.find(";", posDay+1);
                                std::size_t posYear = input.find(";", posMon+1);

                                std::string day = input.substr(posDay+1, posMon-posDay-1);
                                std::string mon = input.substr(posMon+1, posYear-posMon-1);
                                std::string year = input.substr(posYear+1);

                                int iday = std::stoi(day);
                                int imon = std::stoi(mon);
                                int iyear = std::stoi(year);
                                newPerson->setDate(iyear, imon, iday);
                        }

                        if(input.substr(0,10).compare("PERSONALID") == 0)
                                newPerson->setPersonalID(input.substr(11));
                }
        }

        fs.close();
        return true;
}

void writeFile(std::vector<Person*>* pvector, std::string pfilename)
{
        std::fstream fs;
        fs.open(pfilename.c_str(), std::fstream::out);

        for(unsigned int i = 0; i< pvector->size(); i++)
        {
                fs << "BEGIN" << std::endl;
                fs << "NAME:" << (*pvector)[i]->getName() << std::endl;
                fs << "FIRSTNAME:" << (*pvector)[i]->getFirstName() << std::endl;
                if((*pvector)[i]->getSecondName().compare("") != 0)
                        fs << "SECONDNAME:" << (*pvector)[i]->getSecondName() << std::endl;
                fs << "BIRTHDATE:" << (*pvector)[i]->getDate()->tm_mday << ";";
                fs << (*pvector)[i]->getDate()->tm_mon+1 << ";";
                fs << (*pvector)[i]->getDate()->tm_year+1900 << std::endl;
                if((*pvector)[i]->getPersonalID().compare("") != 0)
                        fs << "PERSONALID:" << (*pvector)[i]->getPersonalID() << std::endl;
                fs << "END" << std::endl;
        }

        fs.close();
}
