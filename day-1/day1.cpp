#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

int main() {

    std::ifstream file("input.txt");
    std::string line;
    std::vector<int> left = {};
    std::vector<int> right = {};
    std::string word1, word2;
    size_t totalDistance = 0;

    
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            ss >> word1 >> word2;
            std::cout << word1 << " " << word2 << std::endl;
            left.push_back(std::stoi(word1));
            right.push_back(std::stoi(word2));
        }
        file.close();
    

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    for (auto i = 0; i < left.size(); i++) {
        size_t sum = std::abs(left[i] - right[i]);
        totalDistance += sum;
    }

    std::cout << "Left Vector Length: " << left.size() << std::endl;
    std::cout << "Total distance: " << totalDistance << std::endl;

    return 0;
}