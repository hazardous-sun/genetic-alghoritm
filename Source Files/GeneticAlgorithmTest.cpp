#include <iostream>
#include "../Header Files/Solution.h"
#include "../Header Files/GeneticAlgorithm.h"

int main() {
    std::cout << "Hi, student!\n";
    int populationSize = 100;
    int bits = 8;
    int low = 0;
    int high = 4;
    GenericAlgorithm ga(100);
    Solution bestSolution = ga.run(bits, low, high);
}