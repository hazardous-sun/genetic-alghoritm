#include <iostream>
#include "../Header Files/Solution.h"
#include "../Header Files/GeneticAlgorithm.h"

int main() {
    int populationSize = 100;
    int generations = 10;
    int tournamentGroupSize = 3;
    double crossoverProbability = 0.7;
    double mutationProbability = 0.01;
    int bits = 8;
    int low = 0;
    int high = 4;
    GenericAlgorithm ga(populationSize, generations, tournamentGroupSize, crossoverProbability, mutationProbability);
    Solution bestSolution = ga.run(bits, low, high);
}