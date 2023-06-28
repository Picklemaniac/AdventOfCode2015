#include <iostream>
#include <sstream>
#include "Day6.h"

Day6::Day6(const std::string &fileName) : BaseDay(fileName) {
    for (const auto &i: input) {
        std::istringstream lineStream(i);
        Command command;
        std::string action;

        if (i.substr(0, 4) == "turn") {
            lineStream >> command.action;
            std::string onOff;
            lineStream >> onOff;
            command.action += " " + onOff;
        } else {
            lineStream >> command.action;
        }

        std::string through;

        lineStream >> command.x1;
        lineStream.ignore(1);
        lineStream >> command.y1;
        lineStream >> through;
        lineStream >> command.x2;
        lineStream.ignore(1);
        lineStream >> command.y2;

        commands.push_back(command);
    }
}

void Day6::partOne() {
    std::vector<std::vector<int>> grid(1000, std::vector<int>(1000, 0));

    for (auto &command: commands) {
        for (int i = command.y1; i <= command.y2; ++i) {
            for (int j = command.x1; j <= command.x2; ++j) {
                if (command.action == "turn on") {
                    grid[i][j] = 1;
                } else if (command.action == "turn off") {
                    grid[i][j] = 0;
                } else if (command.action == "toggle") {
                    grid[i][j] = (grid[i][j] == 1) ? 0 : 1;
                }
            }
        }
    }

    int lightsOn = 0;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == 1) lightsOn++;
        }
    }

    std::cout << "Total lights on: " << lightsOn;
}

void Day6::partTwo() {
    std::vector<std::vector<int>> grid(1000, std::vector<int>(1000, 0));

    for (auto &command: commands) {
        for (int i = command.y1; i <= command.y2; ++i) {
            for (int j = command.x1; j <= command.x2; ++j) {
                if (command.action == "turn on") {
                    grid[i][j] += 1;
                } else if (command.action == "turn off") {
                    if (grid[i][j] > 0) {
                        grid[i][j] -= 1;
                    }
                } else if (command.action == "toggle") {
                    grid[i][j] += 2;
                }
            }
        }
    }

    int brightness = 0;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            brightness += grid[i][j];
        }
    }

    std::cout << "Total brightness: " << brightness;
}

void Day6::printGrid(std::vector<std::vector<int>> &grid) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }
}