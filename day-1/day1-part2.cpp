#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>    // std::sort
#include <cmath>        // std::abs
#include <map>

int main() {

    std::ifstream file("day1-input.txt");
    std::string line;
    std::vector<int> left = {};
    std::vector<int> right = {};
    std::string word1, word2;
    size_t totalDistance = 0;

    std::map<int, int> numOfOccurrences;

    
    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return 1;
    }

    while (file >> word1 >> word2) {
        if (numOfOccurrences.find(std::stoi(word1)) == numOfOccurrences.end()) {
            numOfOccurrences.insert(std::pair<int, int>(std::stoi(word1), 1));
            //std::cout <<  numOfOccurrences.find(std::stoi(word1))->first << std::endl;
        }
        if (numOfOccurrences.find(std::stoi(word2)) != numOfOccurrences.end()) {
            //std::cout <<  numOfOccurrences.find(std::stoi(word2))->second << std::endl;
            numOfOccurrences[std::stoi(word2)] = numOfOccurrences[std::stoi(word2)] + 1;
        }
    }
    file.close();

    // std::sort(left.begin(), left.end());
    // std::sort(right.begin(), right.end());
    
    for (std::map<int,int>::iterator it=numOfOccurrences.begin(); it!=numOfOccurrences.end(); ++it) {
        std::cout << it->first << " => " << it->second << '\n';
        //std::cout << numOfOccurrences[it->first] * numOfOccurrences[it->second] << "\n";
        totalDistance += numOfOccurrences[it->first] * numOfOccurrences[it->second];
    }


    // for (auto i = 0; i < left.size(); i++) {
    //     size_t sum = std::abs(left[i] - right[i]);
    //     totalDistance += sum;
    // }

    //std::cout << "Left Vector Length: " << left.size() << std::endl;
    std::cout << "Total distance: " << totalDistance << std::endl;

    return 0;
}