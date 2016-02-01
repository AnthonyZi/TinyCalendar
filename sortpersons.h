#ifndef SORTPERSONS_H
#define SORTPERSONS_H

#include <vector>
#include <algorithm>
#include "person.h"

//0 = name ; 1 = date
void sortPersons(std::vector<Person*>* pvector, int mode = 0);

#endif
