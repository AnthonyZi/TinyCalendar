#include "person.h"

Person::Person() : name("-"), firstName(""), secondName(""), personalId("%")
{
        birthdate.tm_year = 0;
        birthdate.tm_mon = 0;
        birthdate.tm_day = 1;

        birthdate.tm_hour = 0;
        birthdate.tm_min = 0;
        birthdate.tm_sec = 0;
        birthdate.tm_isdst = 0;
}

struct tm Person::getDate()
{
        return birthdate;
}

std::string Person::getName()
{
        return name;
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
        birthdate.tm_day = day;
}

void Person::setPersonalId(std::string pid)
{
        personalID = pid;
}

std::string Person::getString()
{
}

std::ostream& operator<< (std::ostream& pstream, const Person& pperson)
{
        pstream << pperson.getName();
        return pstream;
}
