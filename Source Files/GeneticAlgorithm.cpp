#include "../Header Files/GeneticAlgorithm.h"
#include "../Header Files/Utils.h"

#include <ctime>
#include <set>

GenericAlgorithm::GenericAlgorithm(
        int populationSize,
        int generations,
        int tournamentGroupSize,
        double crossOverProbability,
        double mutationProbability
) :
        mPopulationSize(populationSize),
        mGenerations(generations),
        mTournamentGroupSize(tournamentGroupSize),
        mCrossoverProbability(crossOverProbability),
        mMutationProbability(mutationProbability) {

}

Solution GenericAlgorithm::run(int numberOfBits, int low, int high) {
    Solution best(numberOfBits, low, high);
    srand(time(NULL));

    std::vector<Solution> currentGeneration;

    // Gets the first generation
    for (int i = 0; i < mPopulationSize; i++) {
        currentGeneration.push_back(Solution(numberOfBits, low, high));
    }

    // Crosses the solutions
    for (int i = 0; i < mGenerations; i++) {
        std::vector<Solution> crossedSolutions = tournamentCrossover(currentGeneration);
        for (Solution s: crossedSolutions) {
            s.mutate(mMutationProbability);
        }
        currentGeneration = crossedSolutions;
    }

    double maxFitness = currentGeneration[0].fitness();
    best = currentGeneration[0];

    for (int i = 0; i < mPopulationSize; i++) {
        double fitness = currentGeneration[i].fitness();
        if (fitness > maxFitness) {
            maxFitness = fitness;
            best = currentGeneration[i];
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

        // Perform crossover
        std::vector<Solution> children = winner1.singlePointCrossover(winner2, mCrossoverProbability);
        newSolution.push_back(children[0]);
        newSolution.push_back(children[1]);
    }
    return newSolution;
}