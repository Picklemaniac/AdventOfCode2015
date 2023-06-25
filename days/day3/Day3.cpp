#include <iostream>
#include <map>
#include "Day3.h"

Day3::Day3(const std::string &fileName) : BaseDay(fileName) {

}

void Day3::partOne() {
    std::map<std::pair<int, int>, int> cords;
    int currentX = 0;
    int currentY = 0;
    cords[{currentX, currentY}] = 0;

    for (char i : input[0]) {
        currentX += (i == '>') ? 1 : (i == '<') ? -1 : 0;
        currentY += (i == '^') ? 1 : (i == 'v') ? -1 : 0;
        cords[{currentX, currentY}] = 0;
    }

    std::cout << cords.size();
}

void Day3::partTwo() {
    std::map<std::pair<int, int>, int> cords;
    int santaX = 0;
    int santaY = 0;

    int roboX = 0;
    int roboY = 0;

    cords[{santaX, santaY}] = 0;

    for (int i = 0; i < input[0].size(); i+=2) {
        santaX += (input[0][i] == '>') ? 1 : (input[0][i] == '<') ? -1 : 0;
        santaY += (input[0][i] == '^') ? 1 : (input[0][i] == 'v') ? -1 : 0;

        roboX += (input[0][i + 1] == '>') ? 1 : (input[0][i + 1] == '<') ? -1 : 0;
        roboY += (input[0][i + 1] == '^') ? 1 : (input[0][i + 1] == 'v') ? -1 : 0;

        cords[{santaX, santaY}] = 0;
        cords[{roboX, roboY}] = 0;
    }

    std::cout << cords.size();
}
