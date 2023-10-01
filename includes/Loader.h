#ifndef FILE_READER_H
#define FILE_READER_H

#include <iostream>
#include <queue>
#include <map>

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
        static queue<int> readFile(const string &filename);
};

#endif // FILE_READER_H