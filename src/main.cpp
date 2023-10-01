#include "../includes/Loader.h"

using std::string;
using std::endl;
using std::ifstream;
using std::queue;
using std::cerr;
using std::cout;

struct allocation {
    std::size_t size;
    void *space;
};


std::list<allocation> occupied_mem;
std::list<allocation> free_mem;




int main(int argc, char* argv[]) 
{

    string filename = argv[1];
    ifstream inputFile(filename);

    if (!inputFile)
    {
        cerr << "Error: Unable to open file " << filename << endl;
        return 1;
    }

    queue<std::string> processes = Loader::readFile(filename);

    

    return 0;
}