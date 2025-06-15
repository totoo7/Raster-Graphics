#ifndef IMAGE_BASE_HPP
#define IMAGE_BASE_HPP

#include "Image.hpp"
#include <vector>

template<typename T>
class ImageBase : public Image {
    public:
        ImageBase();
        ImageBase(const std::string& filename);
        void rotate(const std::string& direction) override;
        void flip(const std::string& direction) override;
        ~ImageBase() = default;
    protected:
        std::vector<std::vector<T>> paste_pixels(const std::vector<std::vector<T>>& dest, const std::vector<std::vector<T>>& src,
            size_t pos_y, size_t pos_x);
    private:
        void transpose_matrix(std::vector<std::vector<T>>& array);
        void reverse_rows(std::vector<std::vector<T>>& array);
        void reverse_cols(std::vector<std::vector<T>>& array);
    protected:
        std::vector<std::vector<T>> pixels;
};

template<typename T>
inline ImageBase<T>::ImageBase() : Image() {}

template<typename T>
inline ImageBase<T>::ImageBase(const std::string& filename) : Image(filename) {}

template<typename T>
inline void ImageBase<T>::transpose_matrix(std::vector<std::vector<T>>& array) {
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
inline void ImageBase<T>::rotate(const std::string& direction) {
    if (direction == "left") {
        transpose_matrix(pixels);
        reverse_rows(pixels);
    } else if (direction == "right") {
        transpose_matrix(pixels);
        reverse_cols(pixels);
    }
}

template<typename T>
inline void ImageBase<T>::flip(const std::string& direction) {
    if (direction == "top") {
        reverse_rows(pixels);
    } else if (direction == "left") {
        reverse_cols(pixels);
    }
}

template<typename T>
inline void ImageBase<T>::reverse_rows(std::vector<std::vector<T>>& array) {
    for (size_t i = 0; i < array.size() / 2; ++i) {
        std::swap(array[i], array[array.size() - i - 1]);
    }
}

template<typename T>
inline void ImageBase<T>::reverse_cols(std::vector<std::vector<T>>& array) {
    for (size_t i = 0; i < array.size(); ++i) {
        for (size_t j = 0; j < array[i].size() / 2; ++j) {
            std::swap(array[i][j], array[i][array[i].size() - j - 1]);
        }
    } 
}

template<typename T>
inline std::vector<std::vector<T>> ImageBase<T>::paste_pixels(const std::vector<std::vector<T>>& dest,
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


#endif