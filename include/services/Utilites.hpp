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

    template<typename T>
    inline void transpose_matrix(std::vector<std::vector<T>>& array) {
        size_t rows = array.size();
        size_t cols = array[0].size();
        std::vector<std::vector<T>> transposed(cols, std::vector<T>(rows));
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                transposed[j][i] = array[i][j];
            }
        }
        array = std::move(transposed);
    }

    template<typename T>
    inline void reverse_rows(std::vector<std::vector<T>>& array) {
        for (size_t i = 0; i < array.size() / 2; ++i) {
            std::swap(array[i], array[array.size() - i - 1]);
        }
    }

    template<typename T>
    inline void reverse_cols(std::vector<std::vector<T>>& array) {
        for (size_t i = 0; i < array.size(); ++i) {
            for (size_t j = 0; j < array[i].size() / 2; ++j) {
                std::swap(array[i][j], array[i][array[i].size() - j - 1]);
            }
        } 
    }

};

#endif