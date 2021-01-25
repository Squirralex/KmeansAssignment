#include <iostream>
#include "Kmeans.h"
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

	int k = 3;

	vector<vector<float>> data {{2, 10},
							  {2, 5},
							  {8, 4},
							  {5, 8},
							  {7, 5},
							  {6, 4},
							  {1, 2},
							  {4, 9},};

	std::vector<std::vector<float>> initialCentroids {{2, 10},
													  {5, 8},
													  {1, 2}};

	Kmeans kmeans(k, data, initialCentroids);
	kmeans.calculate();
}
