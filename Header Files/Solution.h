#pragma once

#include <vector>
#include <string>

class Solution {
public:
    Solution(int numberOfBits, int low, int high);

    std::string toString() const;

    double fitness() const;

private:
    double bitsToDouble() const;

private:
    int mNumberOfBits, mLow, mHigh;
    std::vector<int> mBits;
};