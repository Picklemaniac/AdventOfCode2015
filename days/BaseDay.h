#pragma once
#include <string>
#include <vector>

class BaseDay {
protected:
    std::vector<std::string> input;
public:
    explicit BaseDay(const std::string &fileName);
    virtual void partOne() = 0;
    virtual void partTwo() = 0;
    void solve();
};