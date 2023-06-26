#include <iostream>
#include <unordered_set>
#include "Day5.h"

Day5::Day5(const std::string &fileName) : BaseDay(fileName) {

}

void Day5::partOne() {
    std::vector<std::string> niceStrings;

    for (const auto & i : input) {
        if (has3Vowels(i) && hasDoubleLetters(i) && DoesntContainletters(i)) {
            niceStrings.push_back(i);
        }
    }

    std::cout << "Nice strings: " << niceStrings.size();
}

void Day5::partTwo() {
    std::vector<std::string> niceStrings;

    for (const auto & i : input) {
        if (hasDoublePair(i) && hasOneRepeat(i)) {
            niceStrings.push_back(i);
        }
    }

    std::cout << "Nice strings: " << niceStrings.size();
}

bool Day5::has3Vowels(const std::string &string) {
    int vowelCount = 0;

    for (char c : string) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelCount++;
        }

        if (vowelCount >= 3) {
            return true;
        }
    }

    return false;
}

bool Day5::hasDoubleLetters(const std::string &string) {
    for (int i = 1; i < string.length(); ++i) {
        if (string[i - 1] == string[i]) {
            return true;
        }
    }
    return false;
}

bool Day5::DoesntContainletters(const std::string &string) {
    for (int i = 0; i < string.length() - 1; ++i) {
        if (string[i] == 'a' && string[i + 1] == 'b')
            return false;
        else if (string[i] == 'c' && string[i + 1] == 'd')
            return false;
        else if (string[i] == 'p' && string[i + 1] == 'q')
            return false;
        else if (string[i] == 'x' && string[i + 1] == 'y')
            return false;
    }
    return true;
}

bool Day5::hasDoublePair(const std::string &string) {
    std::unordered_set<std::string> pairs;

    for (size_t i = 0; i < string.length() - 1; i++) {
        std::string pair = string.substr(i, 2);
        if (i + 2 < string.length() && string.substr(i + 2).find(pair) != std::string::npos) {
            return true;
        }
        pairs.insert(pair);
    }

    return false;
}

bool Day5::hasOneRepeat(const std::string &string) {
    for (int i = 0; i < string.length(); ++i) {
        if (string[i] == string[i + 2]) {
            return true;
        }
    }
    return false;
}


