#include "../Header Files/GeneticAlgorithm.h"
#include "../Header Files/Utils.h"

#include <ctime>
#include <iostream>
#include <set>

GenericAlgorithm::GenericAlgorithm(int populationSize, int generations, int tournamentGroupSize) :
        mPopulationSize(populationSize),
        mGenerations(generations),
        mTournamentGroupSize(tournamentGroupSize) {

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

    for (int i = 0; i < mGenerations; i++) {
        std::vector<Solution> crossedSolutions = tournamentCrossover();
    }

    return best;
}

Solution GenericAlgorithm::tournamentWinner(std::vector<Solution> const &currentGeneration) {
    std::vector<Solution> candidates;
    std::set<int> randomNumbers = randomDistinctNumbers(mPopulationSize, mTournamentGroupSize);

    for (int rn: randomNumbers) {
        candidates.push_back(currentGeneration[rn]);
    }

    Solution bestCandidate = candidates[0];
    double maxFitness = candidates[0].fitness();

    for (Solution s: candidates) {
        double fitness = s.fitness();

        if (fitness > maxFitness) {
            maxFitness = fitness;
            bestCandidate = s;
        }
    }

    return bestCandidate;
}

std::vector<Solution> GenericAlgorithm::tournamentCrossover(std::vector<Solution> const &currentGeneration) {
    std::vector<Solution> newSolution;
    while (newSolution.size() < mPopulationSize) {
        // Get candidates
        Solution winner1 = tournamentWinner(currentGeneration);
        Solution winner2 = tournamentWinner(currentGeneration);

        // Perform crossover
        std::vector<Solution> children = singlePointCrossover(winner1, winner2);
    }
}