#include "../Header Files/Utils.h"
#include <cstdlib>
#include <stdexcept>
#include <set>
#include <math.h>

// returns a random double
double randomDouble()
{
    // gets a random integer, guarantees that it is between 0 and 999 and then guarantee that it is between 0 and 0.999
    return double(rand() % 1000) / 1000;
}

// receives a probability and returns a bool value checking if the probability was met or not
bool randomProbability(double probability)
{
    if (probability < 0 || probability>1)
    {
        throw std::runtime_error("Probability should be between 0 and 1");
    }
    double r = randomDouble();
    if (r < probability)
    {
        return true;
    }
    return false;
}

double precision(int numberOfBits, int low, int high)
{
    double prec = (double)(high - low) / (double)(pow(2, numberOfBits) - 1);
    return prec;
}

std::set<int> randomDistinctNumbers(int upperLimit, int howManyNumbers)
{

    std::set<int> numbers;
    while (numbers.size() < howManyNumbers)
    {
        numbers.insert(rand() % upperLimit);
    }
    return numbers;
}

