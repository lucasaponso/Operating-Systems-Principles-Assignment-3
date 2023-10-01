#include "includes/Loader.h"

queue<int> Loader::readFile(const string &filename)
{
    queue<pcb> processes;
    string line;
    ifstream inputFile(filename);
    while (getline(inputFile, line)) 
    {
        istringstream ss(line);
        string key, value;
        if (getline(ss, key, ',') && getline(ss, value)) 
        {
            pcb process;
            process.set_id(stoi(key));
            process.set_burst_time(stoi(value));
            processes.push(process);
        }
    }
    inputFile.close();
    return processes;
}