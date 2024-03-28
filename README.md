# Genetic Algorithm

Designed to explore fundamental AI concepts and optimization algorithms, this project implements a simple Genetic
Algorithm (GA) to find the optimal value for the function $f(x) = x + 2sin(x)$ within a specified range.

## Project Structure

The project is organized into the following folders:

* Source Files: Contains the source code for the different parts of the program.
    * GeneticAlgorithmTest.cpp: The main file where the Genetic Algorithm is run.
    * Solution.cpp: Contains the implementation of the Solution class, representing a candidate solution in the search
      space.
    * GeneticAlgorithm.cpp: Implements the GeneticAlgorithm class, responsible for managing the population and
      performing genetic operations.
    * Utils.cpp: Provides utility functions used by other parts of the code.
* Header Files: Contains header files declaring the classes and functions used in the project.

## Prerequisites

* Make sure you have CMake installed on your system. You can download it from https://cmake.org/download/.

## Running the Program

The program can be compiled and run using CMake. Here's a general guideline:

1. Compile: Navigate to the project directory in your terminal and run the following command:

```bash
cmake .
```

2. Build: Depending on your operating system, you might need to use a different command to build the executable. Here
   are some common examples:

```bash
make
```

3. Run: Once the build is successful, you should have an executable file named genetic_algorithm (or something similar)
   in the project directory. Run it from the terminal:

```bash
./genetic_algorithm
```

## Code Explanation

The code implements a basic Genetic Algorithm to optimize the function f(x) = x + 2sin(x). Here's a brief overview of
the key components:

* Solution class: This class represents a candidate solution in the search space. It holds a binary string of a fixed
  length and provides methods to calculate its fitness value (based on the function f(x)), convert the binary string to
  a real number, perform mutations, and perform single-point crossover with another solution.
* GeneticAlgorithm class: This class manages the population of solutions, performs selection using a tournament
  selection approach, applies crossover and mutation operations, and iterates through generations to evolve the
  population towards better solutions.
* Utils.cpp: This file contains helper functions used throughout the program, such as generating random numbers,
  checking probabilities, calculating precision for conversion between binary and real values, and generating sets of
  distinct random numbers.

## Configuration

The parameters for the GA can be modified in the GeneticAlgorithmTest.cpp file. These parameters include:

* populationSize: The number of solutions in each generation.
* generations: The number of generations to run the GA for.
* tournamentGroupSize: The size of the group used in tournament selection.
* crossoverProbability: The probability of performing crossover between two selected solutions.
* mutationProbability: The probability of mutating a bit in a solution.
* bits: The number of bits used to represent a solution (defines the search resolution).
* low: The lower bound of the search range for the solution.
* high: The upper bound of the search range for the solution.
