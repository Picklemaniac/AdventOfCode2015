#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Day2.h"

Day2::Day2(const std::string &fileName) : BaseDay(fileName) {

}

void Day2::partOne() {
    int total = 0;

    for (int i = 0; i < input.size(); ++i) {
        std::vector<int> temp = splitStringToNumbers(input.at(i));
        std::vector<int> sides;
        sides.push_back(temp.at(0) * temp.at(1));
        sides.push_back(temp.at(1) * temp.at(2));
        sides.push_back(temp.at(2) * temp.at(0));

        total += ((2 * sides.at(0)) + (2 * sides.at(1)) + (2 * sides.at(2)));
        total += *min_element(sides.begin(), sides.end());
    }

    std::cout << total << " feet of wrapping paper";
}

void Day2::partTwo() {
    int total = 0;

    for (int i = 0; i < input.size(); ++i) {
        std::vector<int> temp = splitStringToNumbers(input.at(i));
        std::sort(temp.begin(), temp.end());
        total += temp.at(0) * 2 + temp.at(1) * 2;
        total += (temp.at(0) * temp.at(1) * temp.at(2));
    }

    std::cout << total << " feet of ribbon";
}

std::vector<int> Day2::splitStringToNumbers(std::string &toSplit) {
    std::vector<int> numbers;
    std::stringstream string(toSplit);
    std::string temp;

    while (std::getline(string, temp, 'x')) {
        numbers.push_back(std::stoi(temp));
    }

    return numbers;
}