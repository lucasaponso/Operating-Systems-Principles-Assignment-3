//include statements (file)
#include "../includes/Syscall.h"
#include "../includes/Allocation.h"

// In Syscall.cpp, update your alloc function
void* alloc(std::size_t chunk_size) 
{
    if (chunk_size == 0) 
    {
        return nullptr;
    }    
    // Determine the chunk size to allocate
    std::size_t actual_chunk_size = 0;
    if (chunk_size <= 32)
    {
        actual_chunk_size = 32;
    }
    else if (chunk_size <= 64)
    {
        actual_chunk_size = 64;
    }
    else if (chunk_size <= 128)
    {
        actual_chunk_size = 128;
    }
    else if (chunk_size <= 256)
    {
        actual_chunk_size = 256;
    }
    else
    {
        actual_chunk_size = 512;
    }

    for (auto it = freeList.begin(); it != freeList.end(); ++it) 
    {
        if (it->size >= actual_chunk_size) 
        {
            void* allocated_space = it->space;

            if (it->size == actual_chunk_size) 
            {
                freeList.erase(it);
            } 
            else 
            {
                it->size -= actual_chunk_size;
                it->space = static_cast<char*>(it->space) + actual_chunk_size;
            }

            Allocation allocation;
            allocation.size = chunk_size;
            allocation.space = allocated_space;
            allocation.num_bytes = actual_chunk_size;
            allocatedList.push_back(allocation);

            return allocated_space;
        }
    }

    void* new_space = sbrk(actual_chunk_size);
    if (new_space == reinterpret_cast<void*>(-1)) 
    {
        return nullptr;
    }

    Allocation allocation;
    allocation.size = chunk_size;
    allocation.space = new_space;
    allocation.num_bytes = actual_chunk_size;
    allocatedList.push_back(allocation);

    return new_space;
}
void* bestfit_alloc(std::size_t chunk_size) 
{
    if (chunk_size == 0) 
    {
        return nullptr;
    }

    // Determine the chunk size to allocate
    std::size_t actual_chunk_size = 0;
    if (chunk_size <= 32)
    {
        actual_chunk_size = 32;
    }
    else if (chunk_size <= 64)
    {
        actual_chunk_size = 64;
    }
    else if (chunk_size <= 128)
    {
        actual_chunk_size = 128;
    }
    else if (chunk_size <= 256)
    {
        actual_chunk_size = 256;
    }
    else
    {
        actual_chunk_size = 512;
    }

    auto best_it = freeList.end();  // Initialize to the end of the freeList.
    std::size_t best_size = std::numeric_limits<std::size_t>::max();  // Initialize to a very large value.

    for (auto it = freeList.begin(); it != freeList.end(); ++it) 
    {
        if (it->size >= actual_chunk_size && it->size < best_size) 
        {
            best_it = it;
            best_size = it->size;
        }
    }

    if (best_it != freeList.end()) 
    {
        void* allocated_space = best_it->space;

        if (best_it->size == actual_chunk_size) 
        {
            freeList.erase(best_it);
        } 
        else 
        {
            best_it->size -= actual_chunk_size;
            best_it->space = static_cast<char*>(best_it->space) + actual_chunk_size;
        }

        Allocation allocation;
        allocation.size = chunk_size;
        allocation.space = allocated_space;
        allocation.num_bytes = actual_chunk_size;
        allocatedList.push_back(allocation);

        return allocated_space;
    }

    void* new_space = sbrk(actual_chunk_size);
    if (new_space == reinterpret_cast<void*>(-1)) 
    {
        return nullptr;
    }

    Allocation allocation;
    allocation.size = actual_chunk_size;
    allocation.space = new_space;
    allocation.num_bytes = actual_chunk_size;
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
