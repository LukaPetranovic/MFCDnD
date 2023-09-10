#include "pch.h"
#include "StatCalculator.hpp"
#include <random>
#include "MFCDnDDlg.h"
#include <numeric>

StatCalculator::StatCalculator() {
}

int StatCalculator::CalculateRandomStat() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);

    std::vector<int> randomNumbers(4);
    std::generate(randomNumbers.begin(), randomNumbers.end(), [&]() { return dis(gen); });

    int smallestNumber = *std::min_element(randomNumbers.begin(), randomNumbers.end());

    int sum = std::accumulate(randomNumbers.begin(), randomNumbers.end(), 0);

    int modifiedStat = sum - smallestNumber;

    while (modifiedStat < 8) {
        std::generate(randomNumbers.begin(), randomNumbers.end(), [&]() { return dis(gen); });
        smallestNumber = *std::min_element(randomNumbers.begin(), randomNumbers.end());
        sum = std::accumulate(randomNumbers.begin(), randomNumbers.end(), 0);
        modifiedStat = sum - smallestNumber;

        if (modifiedStat > 21) {
            modifiedStat = 21;
        }
    }

    return modifiedStat;
}