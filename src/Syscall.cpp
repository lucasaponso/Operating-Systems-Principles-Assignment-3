//include statements (file)
#include "../includes/Syscall.h"
#include "../includes/Allocation.h"

void* alloc(std::size_t chunk_size) 
{
    if (chunk_size == 0) 
    {
        return nullptr;
    }

    for (auto it = freeList.begin(); it != freeList.end(); ++it) 
    {
        if (it->size >= chunk_size) 
        {
            void* allocated_space = it->space;

            if (it->size == chunk_size) 
            {
                freeList.erase(it);
            } 
            else 
            {
                it->size -= chunk_size;
                it->space = static_cast<char*>(it->space) + chunk_size;
            }
            
            Allocation allocation;
            allocation.size = chunk_size;
            allocation.space = allocated_space;
            allocatedList.push_back(allocation);

            return allocated_space;
        }
    }

    void* new_space = sbrk(chunk_size);
    if (new_space == reinterpret_cast<void*>(-1)) 
    {
        return nullptr;
    }

    Allocation allocation;
    allocation.size = chunk_size;
    allocation.space = new_space;
    allocatedList.push_back(allocation);

    return new_space;
}

void* bestfit_alloc(std::size_t chunk_size) {
    if (chunk_size == 0) {
        return nullptr;
    }

    auto best_it = freeList.end();  // Initialize to the end of the freeList.
    std::size_t best_size = std::numeric_limits<std::size_t>::max();  // Initialize to a very large value.

    for (auto it = freeList.begin(); it != freeList.end(); ++it) {
        if (it->size >= chunk_size && it->size < best_size) {
            best_it = it;
            best_size = it->size;
        }
    }

    if (best_it != freeList.end()) {
        void* allocated_space = best_it->space;

        if (best_it->size == chunk_size) {
            freeList.erase(best_it);
        } else {
            best_it->size -= chunk_size;
            best_it->space = static_cast<char*>(best_it->space) + chunk_size;
        }

        Allocation allocation;
        allocation.size = chunk_size;
        allocation.space = allocated_space;
        allocatedList.push_back(allocation);

        return allocated_space;
    }

    void* new_space = sbrk(chunk_size);
    if (new_space == reinterpret_cast<void*>(-1)) {
        return nullptr;
    }

    Allocation allocation;
    allocation.size = chunk_size;
    allocation.space = new_space;
    allocatedList.push_back(allocation);

    return new_space;
}


void dealloc(void* chunk) 
{
    for (auto it = allocatedList.begin(); it != allocatedList.end(); ++it) 
    {
        if (it->space == chunk) 
        {
            freeList.push_back(*it);
            allocatedList.erase(it);
            return;
        }
    }
    cerr << "Error: Attempted to deallocate memory that was not allocated." << endl;
}
