#include "Day4.h"
#include "md5.h"

Day4::Day4(const std::string &fileName) : BaseDay(fileName) {

}

void Day4::partOne() {

    bool found = false;
    int index = 0;

    while (!found) {
        index++;
        std::string hash = md5( input[0] + std::to_string(index));
        if (hash.substr(0, 6) == "00000") {
            found = true;
        }
    }

    std::cout << index;
}

void Day4::partTwo() {

    bool found = false;
    int index = 0;

    while (!found) {
        index++;
        std::string hash = md5( input[0] + std::to_string(index));
        if (hash.substr(0, 6) == "000000") {
            found = true;
        }
    }

    std::cout << index;

}
