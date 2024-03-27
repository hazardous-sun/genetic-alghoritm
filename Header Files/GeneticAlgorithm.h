#pragma once

#include "Solution.h"

class GenericAlgorithm {
public:
    GenericAlgorithm(int populationSize, int generations);

    Solution run(int numberOfBits, int low, int high);

private:
    int mPopulationSize;
    int mGenerations;
};