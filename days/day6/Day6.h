#pragma once
#include "../BaseDay.h"

struct Command {
    std::string action;
    int x1{}, y1{}, x2{}, y2{};
};

class Day6 : public BaseDay {
private:
    std::vector<Command> commands;
public:
    Day6(const std::string &fileName);
    void partOne() override;
    void partTwo() override;
    void printGrid(std::vector<std::vector<int>> &grid);
};