#include "Utils.h"
#include <fstream>

namespace Utils {
    std::vector<std::string> readFile(const std::string &fileName) {

        std::ifstream new_file(fileName);
        std::vector<std::string> lines;
        std::string line;

        while (std::getline(new_file, line)) {
            lines.push_back(line);
        }

        return lines;
    }
}