//include statements (file)
#include "../includes/Loader.h"
#include "../includes/Allocation.h"
#include "../includes/Syscall.h"  // Include the Syscall header
#include <iostream>
#include <list>
#include <fstream>
#include <string>

list<string> loadInstructions(const string& filename) {
    list<string> instructions;
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return instructions;
    }

    string line;
    while (getline(inputFile, line)) {
        instructions.push_back(line);
    }

    inputFile.close();
    return instructions;
}

void processInstructions(const list<string>& instructions, string mem_strategy) 
{
    for (const string& instruction : instructions) 
    {
        if (instruction.find("alloc:") != string::npos) 
        {
            size_t chunk_size = stoul(instruction.substr(7));
            void* allocated_memory = nullptr;  // Declare allocated_memory here

            if (mem_strategy == "./bestfit")
            {
                allocated_memory = bestfit_alloc(chunk_size);
            }
            else if (mem_strategy == "./firstfit")
            {
                allocated_memory = alloc(chunk_size);
            }
            
            if (allocated_memory == nullptr) 
            {
                cerr << "Error: Memory allocation failed." << endl;
            }
        } 
        else if (instruction == "dealloc") 
        {
            if (!allocatedList.empty()) 
            {
                void* memory_to_deallocate = allocatedList.back().space;
                dealloc(memory_to_deallocate);
            } 
            else 
            {
                cerr << "Error: No memory chunks to deallocate." << endl;
            }
        } 
        else 
        {
            cerr << "Error: Invalid instruction in input file: " << instruction << endl;
        }
    }
}
