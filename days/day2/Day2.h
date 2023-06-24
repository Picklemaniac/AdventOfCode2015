#pragma once
#include "../BaseDay.h"

class Day2 : public BaseDay {
public:
    Day2(const std::string &fileName);
    void partOne() override;
    void partTwo() override;
    std::vector<int> splitStringToNumbers(std::string &toSplit);
};
