#include "../Header Files/GeneticAlgorithm.h"

#include <iostream>

GenericAlgorithm::GenericAlgorithm(int populationSize) :
        mPopulationSize(populationSize) {

}

Solution GenericAlgorithm::run(int numberOfBits, int low, int high) {
    Solution best(numberOfBits, low, high);

    std::vector<Solution> currentGeneration;

    for (int i = 0; i < mPopulationSize; i++) {
        currentGeneration.push_back(Solution(numberOfBits, low, high));
    }

    std::cout << "First generation>\n";
    for (Solution s: currentGeneration) {
        std::cout << s.toString() << "\n";
    }

    return best;
}