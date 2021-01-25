#include "Kmeans.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

Kmeans::Kmeans(int k, std::vector<std::vector<float>> data, std::vector<std::vector<float>> centroids): k(k), data(data), centroids(centroids) {}

void Kmeans::calculate() {
    int iterationNumber = 0;
    std::stringstream outputStingStream;
    //LOOP
    while(true) {
        iterationNumber++;

        std::vector<std::vector<float>> cluster1;
        std::vector<std::vector<float>> cluster2;
        std::vector<std::vector<float>> cluster3;
        //for each data point
        for (int i = 0; i < data.size(); i++) {
            //measure distance between point and centroids
            float dist;
            int clusterNumber;
            dist = distance(data[i], centroids[0]);
            clusterNumber = 1;
            if (distance(data[i], centroids[1]) < dist) {
                dist = distance(data[i], centroids[1]);
                clusterNumber = 2;
            }
            if (distance(data[i], centroids[2]) < dist) {
                clusterNumber = 3;
            }
            //assign data point to nearest centroid cluster
            if (clusterNumber == 1) {
                cluster1.push_back(data[i]);
            }
            else if (clusterNumber == 2) {
                cluster2.push_back(data[i]);
            }
            else {
                cluster3.push_back(data[i]);
            }
        }

        //for each cluster (k)
        //calculate mean of each cluster
        //make the mean the new centroid
        //break loop if the new centroids equal the old centroids
        if (centroids[0] == clusterMean(cluster1) && centroids[1] == clusterMean(cluster2) && centroids[2] == clusterMean(cluster3)) {
            break;
        }
        centroids[0] = clusterMean(cluster1);
        centroids[1] = clusterMean(cluster2);
        centroids[2] = clusterMean(cluster3);

        outputStingStream << "Iteration " << iterationNumber << "\n"<< std::endl;

        outputStingStream << "Cluster 1: ";
        for (int i = 0; i < cluster1.size(); i++) {outputStingStream << getPointID(cluster1[i]) << ", ";}
        outputStingStream << "" << std::endl;
        outputStingStream << "Centroid: " << centroids[0][0] << ", " << centroids[0][1] << std::endl;
        outputStingStream << "" << std::endl;

        outputStingStream << "Cluster 2: ";
        for (int i = 0; i < cluster2.size(); i++) {outputStingStream << getPointID(cluster2[i]) << ", ";}
        outputStingStream << "" << std::endl;
        outputStingStream << "Centroid: " << centroids[1][0] << ", " << centroids[1][1] << std::endl;
        outputStingStream << "" << std::endl;

        outputStingStream << "Cluster 3: ";
        for (int i = 0; i < cluster3.size(); i++) {outputStingStream << getPointID(cluster3[i]) << ", ";}
        outputStingStream << "" << std::endl;
        outputStingStream << "Centroid: " << centroids[2][0] << ", " << centroids[2][1] << std::endl;
        outputStingStream << "\n" << std::endl;
    }
    std::cout << outputStingStream.str();

        std::ofstream outputFile;
        outputFile.open("Output.txt");
        outputFile << outputStingStream.str();
        outputFile.close();
}

float Kmeans::distance(std::vector<float> point1, std::vector<float> point2) {
    /*
    Finds and returns distance between 2 points
    */
    return std::sqrt(std::pow((point2[0] - point1[0]), 2) + std::pow((point2[1] - point1[1]), 2));
}

std::vector<float> Kmeans::clusterMean(std::vector<std::vector<float>> cluster) {
    /*
    Finds and returns the mean point of the given cluster
    */
    std::vector<float> totalPoint = {0, 0};
    for (int i = 0; i < cluster.size(); i++) {
        totalPoint[0] = totalPoint[0] + cluster[i][0];
        totalPoint[1] = totalPoint[1] + cluster[i][1];
    }
    totalPoint[0] = (totalPoint[0])/(cluster.size());
    totalPoint[1] = (totalPoint[1])/(cluster.size());
    return totalPoint;
    
}

int Kmeans::getPointID(std::vector<float> point) {
    /* 
    Returns the ID (the position from the data array + 1) of the specified point
    */
    for (int i = 0; i < data.size(); i++) {
        if (point == data[i]) {
            return i + 1;
        }
    }
    return 0;
}