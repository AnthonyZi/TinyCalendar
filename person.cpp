#include "person.h"

Person::Person() : name("-"), firstName(""), secondName(""), personalID("")
{
        birthdate.tm_year = 0;
        birthdate.tm_mon = 0;
        birthdate.tm_mday = 1;

        birthdate.tm_hour = 0;
        birthdate.tm_min = 0;
        birthdate.tm_sec = 0;
        birthdate.tm_isdst = 0;
}

struct tm* Person::getDate()
{
        return &birthdate;
}

std::string Person::getName()
{
        return name;
}

std::string Person::getFirstName()
{
        return firstName;
}

std::string Person::getSecondName()
{
        return secondName;
}

std::string Person::getPersonalID()
{
        return personalID;
}

std::string Person::getString()
{
        std::string result;
        result = std::to_string(birthdate.tm_mday);
        result += ".";
        result += std::to_string(birthdate.tm_mon+1);
        result += ".";
        result += std::to_string(birthdate.tm_year+1900);
        result += " : ";
        result += name;
        result += ", ";
        result += firstName;
        result += " ";
        if(secondName.compare(""))
        {
                result += secondName;
                result += " ";
        }
        if(personalID.compare(""))
        {
                result += "~";
                result += personalID;
                result += "~";
        }
        result += "\n";
        return result;
}

void Person::setName(std::string pname)
{
        name = pname;
}

void Person::setFirstName(std::string pname)
{
        firstName = pname;
}

void Person::setSecondName(std::string pname)
{
        secondName = pname;
}

void Person::setDate(int year, int month, int day)
{
        birthdate.tm_year = year - 1900;
        birthdate.tm_mon = month - 1;
        birthdate.tm_mday = day;
}

void Person::setPersonalID(std::string pid)
{
        personalID = pid;
}

std::ostream& operator<< (std::ostream& pstream, Person& pperson)
{
        pstream << std::right << std::setfill('0');
        pstream << std::setw(2) << pperson.getDate()->tm_mday << ".";
        pstream << std::setw(2) << pperson.getDate()->tm_mon+1 <<  ".";
        pstream << std::setw(4) << pperson.getDate()->tm_year+1900 << " : ";
        pstream << pperson.getName() << ", " << pperson.getFirstName() << " " << pperson.getSecondName();
        if(pperson.getSecondName().compare(""))
                pstream << " ";
        if(pperson.getPersonalID().compare(""))
                pstream << "~" << pperson.getPersonalID() << "~";
        pstream << std::endl;
        return pstream;
}
