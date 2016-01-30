#include <time.h>

class Person
{
private:
        std::string name;
        std::string firstName;
        std::string secondName;

        struct tm birthdate;

        //personal Identifaction
        std::string personalId;
public:
        Person();

        struct tm getDate();
        std::string getName();

        setName(std::string pname);
        setFirstName(std::string pname);
        setSecondName(std::string pname);
        setDate(int year, int month, int day);
        setPersonalId(std::string pid);
}

std::ostream& operator<< (std::osteream&, const Person::Person&);
