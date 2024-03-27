#include "../Header Files/GeneticAlgorithm.h"

#include <ctime>
#include <iostream>

GenericAlgorithm::GenericAlgorithm(int populationSize, int generations) :
        mPopulationSize(populationSize),
        mGenerations(generations) {

}

Solution GenericAlgorithm::run(int numberOfBits, int low, int high) {
    Solution best(numberOfBits, low, high);
    srand(time(NULL));

    std::vector<Solution> currentGeneration;

    for (int i = 0; i < mPopulationSize; i++) {
        currentGeneration.push_back(Solution(numberOfBits, low, high));
    }

    std::cout << "First generation>\n";
    for (Solution s: currentGeneration) {
        std::cout << s.toString() << "\n";
    }

    for (int i = 0; i < mGenerations; i++) {}

    return best;
}