#pragma once

#include "Solution.h"

class GenericAlgorithm {
public:
    GenericAlgorithm(int populationSize);

    Solution run(int numberOfBits, int low, int high);

private:
    int mPopulationSize;
};