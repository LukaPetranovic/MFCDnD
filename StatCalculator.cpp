#include "pch.h"
#include "StatCalculator.hpp"
#include <random>
#include "MFCDnDDlg.h"

int modifiedStat;

StatCalculator::StatCalculator() {
}

int StatCalculator::CalculateRandomStat() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 6);

	do {
		int randomNumbers[4];
		for (int i = 0; i < 4; ++i) {
			randomNumbers[i] = dis(gen);
		}

		int smallestNumber = randomNumbers[0];
		for (int i = 1; i < 4; ++i) {
			if (randomNumbers[i] < smallestNumber) {
				smallestNumber = randomNumbers[i];
			}
		}

		int sum = randomNumbers[0] + randomNumbers[1] + randomNumbers[2] + randomNumbers[3];
		modifiedStat = sum - smallestNumber;
	} while (modifiedStat < 8);

	return modifiedStat;
}