#include "../Header Files/GeneticAlgorithm.h"
#include "../Header Files/Utils.h"

#include <ctime>
#include <iostream>
#include <set>

GenericAlgorithm::GenericAlgorithm(
        int populationSize,
        int generations,
        int tournamentGroupSize,
        double crossOverProbability
) :
        mPopulationSize(populationSize),
        mGenerations(generations),
        mTournamentGroupSize(tournamentGroupSize),
        mCrossoverProbability(crossOverProbability) {

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
        std::vector<Solution> crossedSolutions = tournamentCrossover(currentGeneration);
        std::cout << "Crossed solutions\n";

        for (Solution s: crossedSolutions) {
            std::cout << s.toString() << "\n";
        }
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

        std::cout << "Crossing the winners: " << winner1.toString() << " & " << winner2.toString();

        // Perform crossover
        std::vector<Solution> children = winner1.singlePointCrossover(winner2, mCrossoverProbability);
        newSolution.push_back(children[0]);
        newSolution.push_back(children[1]);

        std::cout << "Children = " << children[0].toString() << " & " << children[1].toString() << "\n";
    }
    return newSolution;
}