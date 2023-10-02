#ifndef ALLOCATION_H
#define ALLOCATION_H

#include <cstddef>
#include <list>

struct Allocation {
    std::size_t size;
    void* space;
};

extern std::list<Allocation> allocatedList;
extern std::list<Allocation> freeList;

void* alloc(std::size_t chunk_size);
void dealloc(void* chunk);

#endif
