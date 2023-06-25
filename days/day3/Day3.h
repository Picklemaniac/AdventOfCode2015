#pragma once
#include "../BaseDay.h"

class Day3 : public BaseDay {
public:
    Day3(const std::string &fileName);
    void partOne() override;
    void partTwo() override;
};