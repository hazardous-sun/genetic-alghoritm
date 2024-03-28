#include "../Header Files/Solution.h"
#include "../Header Files/Utils.h"
#include <cmath>
#include <sstream>
#include <iostream>

Solution::Solution(int numberOfBits, int low, int high) :
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

Solution::Solution(int numberOfBits, int low, int high, std::vector<int> bits) :
        mLow(low),
        mHigh(high),
        mNumberOfBits(numberOfBits),
        mBits(bits) {
}

std::string Solution::toString() const {
    std::ostringstream stream;
    stream << "[";
    for (int bit: mBits) {
        stream << bit << " ";
    }
    stream << "] double = " << bitsToDouble() << " fitness = " << fitness();
    return stream.str();
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

// Optimizes f(x) = x + 2 * sin(x)
double Solution::fitness() const {
    double x = bitsToDouble();
    return x + 2 * sin(x);
}

std::vector<Solution> Solution::singlePointCrossover(Solution other, double crossoverProbability) {
    bool cross = randomProbability(crossoverProbability);
    if (cross) {
        int crossPoint = rand() % mNumberOfBits;

        std::vector<int> bits1;
        std::vector<int> bits2;

        std::copy(this->mBits.begin(), this->mBits.begin() + crossPoint, std::back_inserter(bits1));
        std::copy(other.mBits.begin() + crossPoint, other.mBits.end(), std::back_inserter(bits1));

        std::copy(other.mBits.begin(), other.mBits.begin() + crossPoint, std::back_inserter(bits2));
        std::copy(this->mBits.begin() + crossPoint, this->mBits.end(), std::back_inserter(bits2));

        Solution child1{mNumberOfBits, mLow, mHigh, bits1};
        Solution child2{mNumberOfBits, mLow, mHigh, bits2};

        return {child1, child2};
    } else {
        return {*this, other};
    }
}

void Solution::mutate(double mutationProbability) {
    for (int i = 0; i < mNumberOfBits; i++) {
        bool mutateBool = randomProbability(mutationProbability);

        if (mutateBool) {
            mBits[i] = !mBits[i];
        }
    }
}