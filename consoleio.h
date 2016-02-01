#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include "person.h"
#include "fileio.h"
#include "sortpersons.h"

void consoleUI(std::vector<Person*>* pvector);
std::string getCommand();

void addPerson(std::vector<Person*>* pvector);
void delPerson(std::vector<Person*>* pvector);
void editPerson(std::vector<Person*>* pvector);

void list(std::vector<Person*>* pvector,bool namesort = true, bool all = true, bool withID = false);

void load(std::vector<Person*>* pvector);
void save(std::vector<Person*>* pvector);

void printhelp();

#endif
