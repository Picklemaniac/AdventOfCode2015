#include <iostream>
#include "Day1.h"

Day1::Day1(const std::string &fileName) : BaseDay(fileName) {

}

void Day1::partOne() {
    int floor = 0;
    for (char i : input[0]) {
        floor += (i == '(') ? 1 : (i == ')') ? -1 : 0;
    }
    std::cout << "Santa reaches floor: " << floor;
}

void Day1::partTwo() {
    int floor = 0;
    int position = 0;
    for (char i : input[0]) {
        position++;
        floor += (i == '(') ? 1 : (i == ')') ? -1 : 0;
        if (floor == -1) break;
    }
    std::cout << "Santa reaches the basement on position: " << position;
}