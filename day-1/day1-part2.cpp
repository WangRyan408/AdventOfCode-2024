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
    int totalDistance = 0;

    std::map<int, int> numOfOccurrences;

    
    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return 1;
    }

    while (file >> word1 >> word2) {
        left.push_back(std::stoi(word1));
        right.push_back(std::stoi(word2));
    }
    file.close();

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    
    for (auto i = 0; i < left.size(); i++) {
        for (auto j = 0; j < right.size(); j++) {
            if (numOfOccurrences.find(left[i]) == numOfOccurrences.end()) {
                numOfOccurrences.insert(std::pair<int, int>(left[i], 0));
            }
            else if (numOfOccurrences.find(left[i]) != numOfOccurrences.end() && left[i] == right[j]) {
                numOfOccurrences.at(left[i]) += 1;
            }
        }
    }
    
    
    for (const auto& pair : numOfOccurrences) {
    
        std::cout << "Key: " << pair.first << " Value: " << pair.second << std::endl;
        totalDistance += pair.first * pair.second;

    }


    std::cout << "Total distance: " << totalDistance << std::endl;

    return 0;
}