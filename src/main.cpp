//include statements (file)
#include "../includes/Allocation.h"
#include "../includes/Loader.h"
#include "../includes/Syscall.h"


using std::string;
using std::list;
using std::cerr;
using std::endl;
using std::size_t;
using std::stoul;
using std::cout;
using std::ifstream;

//global variables
list<Allocation> allocatedList;
list<Allocation> freeList;



int main(int argc, char* argv[]) 
{
    //check for number of arguments in execution of program, if not equal to two then exit
    if (argc != 2) 
    {
        cerr << "Usage: " << argv[0] << " <input_filename>" << endl;
        return 1;
    }
    
    //init a string variable to hold the filename
    string filename = argv[1];
    string strategy = argv[0];

    //Check if file exists in FS, if false exit program
    ifstream file(filename);
    if(!file.good())
    {
        cerr << "Error: File '" << filename << "' not found." << endl;
        return 1;
    }

    //pass in the filename to loadinstructions to get instructions and load into linkedlist
    list<string> instructions = loadInstructions(filename);
    //pass linkedlist full of instructions and execute them in processInstructions by using dealloc and alloc
    processInstructions(instructions, strategy);
// In your main.cpp, update the printing of allocated and free lists
cout << "Allocated List:" << endl;
for (const auto& allocation : allocatedList) 
{
    cout << "  Size: " << allocation.size << ", Space: " << allocation.space <<  ", Bytes: " << allocation.num_bytes << endl;
}
// Print the free list
cout << "Free List:" << endl;
for (const auto& allocation : freeList) 
{
   cout << "  Size: " << allocation.size << ", Space: " << allocation.space <<  ", Bytes: " << allocation.num_bytes << endl;
}
    return 0;
}
