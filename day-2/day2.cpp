#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

bool sortHelper (int i, int j) { return i > j; }


bool checkSafety(std::vector<int> &vec) {
    
    int lastNum = vec[0];
    std::vector<int> increasing = vec;
    std::vector<int> decreasing = vec;
    std::sort(increasing.begin(), increasing.end());
    std::sort(decreasing.begin(), decreasing.end(), sortHelper);

    std::cout << std::endl;
    //Print Debugging increasing
    for (int i = 0; i < increasing.size(); i++) {
        std::cout << increasing[i] << " ";
    }
    std::cout << std::endl;
    //Print Debugging decreasing
    for (int i = 0; i < decreasing.size(); i++) {
        std::cout << decreasing[i] << " ";
    }
    std::cout << std::endl;

    //Checks if the vector is either increasing or decreasing, if not return false
    if (increasing != vec || decreasing != vec) return false;

    std::cout << "Passed the first check" << std::endl;
    
    //Checks if the difference between the numbers is either 1 or 3, if not return false
    for (int i = 1; i < vec.size(); i++) {
        if (std::abs(lastNum - vec[i]) < 1 || std::abs(lastNum - vec[i]) > 3) return false;
        lastNum = vec[i]; //Sets lastNum to the current number
    }

    return true;    //If all checks pass, return true
}

int main() {

    // std::ifstream file("day2-input.txt");
    std::ifstream file("test.txt");
    std::string line, num;
    //std::vector<int> safe;
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
        //Print Debugging textLine
        for (int i = 0; i < textLine.size(); i++) {
            std::cout << textLine[i] << " ";
        }
        std::cout << std::endl;

        if (checkSafety(textLine)) {
            safe++;
        }
    }
    file.close();

    std::cout << "# of Safe Reports: " << safe << std::endl;
    return 0;
}
