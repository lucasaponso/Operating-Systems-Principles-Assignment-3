#ifndef SYSCALL_H
#define SYSCALL_H
//include statements (system)
#include <cstring> 
#include <unistd.h>
#include <limits>   
#include <cstring>  
#include <iostream> 
#include <list>
//include statements (file)
#include "Allocation.h"

using std::list;
using std::cerr;
using std::endl;

void* alloc(std::size_t chunk_size);
void dealloc(void* chunk);

#endif // SYSCALL_H
