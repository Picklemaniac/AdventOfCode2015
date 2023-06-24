#include <iostream>
#include "BaseDay.h"
#include "../utils/Utils.h"

BaseDay::BaseDay(const std::string &fileName) {
    input = Utils::readFile(fileName);
}

void BaseDay::solve() {
    std::cout << "Part one: " << std::endl;
    partOne();
    std::cout << std::endl << "Part two: " << std::endl;
    partTwo();
}
