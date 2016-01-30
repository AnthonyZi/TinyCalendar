#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <vector>
#include "person.h"

void consoleUI(std::vector<Person*>* pvector);
std::string getCommand();

void addUser(std::vector<Person*>* pvector);
void delUser(std::vector<Person*>* pvector);

void list(std::vector<Person*>* pvector,bool namesort = true, bool all = true, bool withID = false);

#endif
