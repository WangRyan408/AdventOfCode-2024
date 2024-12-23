#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

bool sortHelper (int i, int j) { return i > j; }

int numOfDiff(std::vector<int> &vec) {
    int numDiffIncreasing = 0;
    int numDiffDecreasing = 0;

    std::vector<int> increasing = vec;
    std::vector<int> decreasing = vec;
    std::sort(increasing.begin(), increasing.end());
    std::sort(decreasing.begin(), decreasing.end(), sortHelper);

    for (size_t i = 0; i < vec.size(); i++) {
        if (increasing[i] != vec[i]) numDiffIncreasing++;
    }

    for (size_t i = 0; i < vec.size(); i++) {
        if (decreasing[i] != vec[i]) numDiffIncreasing++;
    }

    return std::min(numDiffIncreasing, numDiffDecreasing);
}


bool checkDiffer(std::vector<int> &vec) {
    bool lastChance = false;
    int lastNum = vec[0];
    std::vector<int> increasing = vec;
    std::vector<int> decreasing = vec;
    std::sort(increasing.begin(), increasing.end());
    std::sort(decreasing.begin(), decreasing.end(), sortHelper);

    //Checks if the difference between the numbers is either 1 or 3, if not return false
    for (int i = 1; i < vec.size(); i++) {
        if ((std::abs(lastNum - vec[i]) < 1 || std::abs(lastNum - vec[i]) > 3) && lastChance == false) lastChance = true;
        else if ((std::abs(lastNum - vec[i]) < 1 || std::abs(lastNum - vec[i]) > 3) && lastChance == true) return false;
        lastNum = vec[i]; //Sets lastNum to the current number
    }
    if (numOfDiff(vec) < 2) return true;
    //else if (decreasing == vec) return true;
    else return false;    //If all checks pass, return true
}



int main() {

    std::ifstream file("day2-input.txt");
    //std::ifstream file("test.txt");
    std::string line, num;
    int safe = 0;

    //Checks if file is open
    if (!file.is_open()) {
        std::cout << "File not found!\n" << std::endl;
        return -1;
    }

    while (std::getline(file, line)) {
        
        std::stringstream ss(line);
        std::vector<int> textLine;
        std::string word;

        //Pushes a line of numbers into textLine from the file
        while (ss >> word) {
            textLine.push_back(std::stoi(word));
        }
       
        if (checkDiffer(textLine)) {
            safe++;
        }
    }
    file.close();

    std::cout << "# of Safe Reports: " << safe << std::endl;
    return 0;
}
