#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <list>

using std::queue;
using std::vector;
using std::map;
using std::string;
using std::ifstream;
using std::getline;
using std::istringstream;
using std::stoi;

class Loader 
{
    public:
        static queue<std::string> readFile(const string &filename);
};

#endif // FILE_READER_H