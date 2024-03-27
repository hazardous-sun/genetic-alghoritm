cmake_minimum_required(VERSION 3.27)
project(genetic_algorithm)

set(CMAKE_CXX_STANDARD 17)

# Specify include directories for headers
include_directories("Header Files")

# Add source files to the executable
add_executable(genetic_algorithm
        "Source Files/GeneticAlgorithmTest.cpp"
        "Source Files/Solution.cpp"
        "Source Files/GeneticAlgorithm.cpp"
        "Source Files/Utils.cpp"
)
