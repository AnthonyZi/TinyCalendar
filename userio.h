#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "person.h"
#include "fileio.h"

void consoleUI(std::vector<Person*>* pvector);
std::string getCommand();

void addPerson(std::vector<Person*>* pvector, bool console = true);
void delPerson(std::vector<Person*>* pvector, bool console = true);

void list(std::vector<Person*>* pvector,bool namesort = true, bool all = true, bool withID = false, bool console = true);

void load(std::vector<Person*>* pvector, bool console = true);
void save(std::vector<Person*>* pvector, bool console = true);

#endif
