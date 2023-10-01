#include "../includes/Loader.h"

queue<std::string> Loader::readFile(const string &filename)
{
    queue<std::string> sequences;
    string line;
    ifstream inputFile(filename);

    while (getline(inputFile, line)) 
    {
        istringstream ss(line);
        string key, value;
        std::cout << line << std::endl;
    }
    inputFile.close();
    return sequences;
}