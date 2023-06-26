#pragma oncce
#include "../BaseDay.h"

class Day5 : public BaseDay {
public:
    Day5(const std::string &fileName);
    void partOne() override;
    void partTwo() override;
    bool has3Vowels(const std::string &string);
    bool hasDoubleLetters(const std::string &string);
    bool DoesntContainletters(const std::string &string);
    bool hasDoublePair(const std::string &string);
    bool hasOneRepeat(const std::string &string);
};