#ifndef LOADER_H
#define LOADER_H
//include statements (system)
#include <iostream>
#include <fstream>
#include <string>
#include <list>


using std::list;
using std::string;
using std::cerr;
using std::endl;
using std::getline;
using std::ifstream;

list<string> loadInstructions(const string& filename);
void processInstructions(const std::list<std::string>& instructions, string mem_strategy);

#endif  // LOADER_H
