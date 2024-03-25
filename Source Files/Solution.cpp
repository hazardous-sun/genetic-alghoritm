#include "../Header Files/Solution.h"

Solution::Solution(int numberOfBits): mNumberOfBits(numberOfBits) {
    /*
     reserve() is a function that allocates a memory space of size N to the std::vector

     By default, the capacity of a std::vector is 1, and it will reallocate its memory to the double of the current size
     if the capacity is exceeded. Therefore, manually allocating the capacity of the vector can prevent some bugs, as
     well as optimize the runtime, since there won't be any further reallocation.
     */
    mBits.reserve(numberOfBits);
}