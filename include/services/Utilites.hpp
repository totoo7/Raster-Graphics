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

    template<typename T>
    inline std::vector<std::vector<T>> paste_pixels(const std::vector<std::vector<T>>& dest,
    const std::vector<std::vector<T>>& src,
    size_t pos_y,
    size_t pos_x) {

        size_t new_height = std::max(dest.size(), pos_y + src.size());
        size_t new_width  = std::max(dest.empty() ? 0 : dest[0].size(), pos_x + src[0].size());

        std::vector<std::vector<T>> result(new_height, std::vector<T>(new_width));

        for (size_t i = 0; i < dest.size(); ++i) {
            for (size_t j = 0; j < dest[i].size(); ++j) {
                result[i][j] = dest[i][j];
            }
        }

        for (size_t i = 0; i < src.size(); ++i) {
            for (size_t j = 0; j < src[i].size(); ++j) {
                result[pos_y + i][pos_x + j] = src[i][j];
            }
        }

        return result;
    }

};

#endif