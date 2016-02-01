#include "sortpersons.h"

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

void sortPersons(std::vector<Person*>* pvector, int mode)
{
        switch(mode)
        {
        case 0:
                std::sort(pvector->begin(), pvector->end(), nameCompare);
                break;
        case 1:
                std::sort(pvector->begin(), pvector->end(), dateCompare);
                break;
        default:
                break;
        }
}
