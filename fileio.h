#ifndef FILEIO_H
#define FILEIO_H

#include "person.h"
#include <vector>
#include <string>
#include <fstream>
#include <cstring>

bool readFile(std::string pfilename, std::vector<Person*>* pvector);
void writeFile(std::vector<Person*>* pvector, std::string pfilename);

#endif
