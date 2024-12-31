#include <cstddef>
#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>


std::vector<int> split(const std::string& str) {
    std::vector<int> tokens;
    std::stringstream ss(str);
    std::string token;
    
    while (ss >> token) {
        tokens.push_back(std::stoi(token));
    }
    return tokens;
}

std::string trim(std::string s) {
    // Trim from start
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    
    // Trim from end
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    
    return s;
}


std::vector<std::vector<int>> extract_matches(const std::vector<std::string>& strings, const std::string& pattern) {
    std::vector<std::string> results;   // vector to store the regex matches
    std::regex r(pattern);  // mul([0-9]+,[0-9]+)

    std::vector<std::vector<int>> product;
    std::regex num("([0-9]+,[0-9]+)");
    std::regex notNum(R"([^0-9])");
    
    for (const auto& str : strings) {
        auto begin = std::sregex_iterator(str.begin(), str.end(), r);
        auto end = std::sregex_iterator();
        while (begin != end) {
            std::smatch match = *begin;
            results.push_back(match.str());
            ++begin;
        }
    }

    for (auto i = 0; i < results.size(); i++) {
        std::smatch match;
        regex_search(results[i], match, num);
        std::string str = std::regex_replace(results[i], notNum, " ");
        str = trim(str);
        auto numVector = split(str);
        product.push_back(numVector);
    }
    return product;
}

u_int64_t product(std::vector<std::vector<int>> product) {
    u_int64_t result = 0;
    for (auto i = 0; i < product.size(); i++) {
        result += product[i][0] * product[i][1];
    }
    return result;
}


int main() {

    std::string pattern = "mul\\([0-9]+,[0-9]+\\)";
    std::regex instructions_regex("^([a-z]{3})\\((\\d+),(\\d+)\\)$");
    std::smatch match;

    std::ifstream file("day3-input.txt");
    std::string line, num;
    std::vector<std::string> strVec;
    std::vector<std::string> regexVec;

    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return 1;
    }

    while(std::getline(file, line)) {
        strVec.push_back(line);
    }

    file.close();

    std::cout << "Vector Size: " << strVec.size() << std::endl;

    auto productVec = extract_matches(strVec, pattern);
    std::cout << product(productVec) << std::endl;

    std::cout << "Vector containing regex matches:" << std::endl;
    
    return 0;
}


