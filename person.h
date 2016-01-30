#ifndef PERSON_H
#define PERSON_H

#include <time.h>
#include <iostream>
#include <iomanip>

class Person
{
private:
        std::string name;
        std::string firstName;
        std::string secondName;

        struct tm birthdate;

        //personal Identifaction
        std::string personalID;
public:
        Person();

        struct tm* getDate();
        std::string getName();
        std::string getFirstName();
        std::string getSecondName();
        std::string getPersonalID();

        void setName(std::string pname);
        void setFirstName(std::string pname);
        void setSecondName(std::string pname);
        void setDate(int year, int month, int day);
        void setPersonalID(std::string pid);
};

std::ostream& operator<< (std::ostream&, Person& pperson);

#endif
