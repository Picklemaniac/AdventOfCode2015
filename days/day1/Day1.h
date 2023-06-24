#pragma once
#include "../BaseDay.h"

class Day1 : public BaseDay {
public:
    Day1(const std::string &fileName);
    void partOne() override;
    void partTwo() override;
};