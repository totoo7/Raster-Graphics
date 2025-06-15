#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>
#include <string>

namespace UTILITIES {

    inline std::vector<std::string> split(const std::string &value, char delimeter = ' ')
    {
        std::vector<std::string> tokens;
        size_t start = 0, end = 0;
        while ((end = value.find(delimeter, start)) != std::string::npos)
        {
            tokens.push_back(value.substr(start, end - start));
            start = end + 1;
        }
        tokens.push_back(value.substr(start));
        return tokens;
    }

    inline void skip_comments(std::istream& is, int skip_lines = 0) {
        std::string line;
        int lines_skipped = 0;

        while (lines_skipped < skip_lines && std::getline(is, line)) {
            if (!line.empty() && line[0] == '#') continue;
            ++lines_skipped;
        }
        while (is >> std::ws && is.peek() == '#') {
            std::getline(is, line);
        }
    }

};

#endif