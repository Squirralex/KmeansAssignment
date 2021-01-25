#ifndef KMEANS_H
#define KMEANS_H
#include <vector>

class Kmeans {
	private:
		int k;
		std::vector<std::vector<float>> data;
		std::vector<std::vector<float>> centroids;

	public:
		Kmeans(int k, std::vector<std::vector<float>> data, std::vector<std::vector<float>> centroids);
		void calculate();
		float distance(std::vector<float> point1, std::vector<float> point2);
		std::vector<float> clusterMean(std::vector<std::vector<float>> cluster);
		int getPointID(std::vector<float> point);
};

#endif
