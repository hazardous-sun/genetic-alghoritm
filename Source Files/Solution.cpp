#include "../Header Files/Solution.h"
#include "../Header Files/Utils.h"
#include <math.h>
#include <sstream>

Solution::Solution(int low, int high, int numberOfBits) :
        mLow(low),
        mHigh(high),
        mNumberOfBits(numberOfBits) {
    /*
     reserve() is a function that allocates a memory space of size N to the std::vector

     By default, the capacity of a std::vector is 1, and it will reallocate its memory to the double of the current size
     if the capacity is exceeded. Therefore, manually allocating the capacity of the vector can prevent some bugs, as
     well as optimize the runtime, since there won't be any further reallocation.
     */
    mBits.reserve(numberOfBits);

    for (int i = 0; i < numberOfBits; i++) {
        mBits.push_back(rand() % 2);
    }
}

std::string Solution::toString() const {
    std::ostringstream stream;
    stream << "[";
    for (int bit: mBits) {
        stream << bit << " ";
    }
    stream << "] double = " << bitsToDouble();
}

double Solution::bitsToDouble() const {
    double prec = precision(mNumberOfBits, mLow, mHigh);
    int sum = 0;
    for (int i = 0; i < mNumberOfBits; i++) {
        /*
         Converts from base 10 to base 2
         */
        sum = sum + pow(2, i) * mBits[i];
    }
    return sum * prec + mLow;
}