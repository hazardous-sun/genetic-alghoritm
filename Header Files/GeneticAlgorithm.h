#pragma once

#include "Solution.h"

class GenericAlgorithm {
public:
    GenericAlgorithm(int populationSize, int generations, int tournamentGroupSize);

    Solution run(int numberOfBits, int low, int high);

private:
    std::vector<Solution> tournamentCrossover(std::vector<Solution> const &currentGeneration);

    Solution tournamentWinner(std::vector<Solution> const &currentGeneration);

private:
    int mPopulationSize;
    int mGenerations;
    int mTournamentGroupSize;
};