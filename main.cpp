#include <iostream>
using std::cout;
using std::endl;
int main(int argc, char* argv[]) 
{

    if (argc < 2) 
    {
        cout << "No command-line arguments provided." << endl;
        return 1;
    }

    return 0;
}
