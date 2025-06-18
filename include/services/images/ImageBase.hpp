#ifndef IMAGE_BASE_HPP
#define IMAGE_BASE_HPP

#include "Image.hpp"
#include <vector>

/**
 * @class ImageBase
 * @brief A templated abstract class that implements common image functionality.
 * @tparam T Type used to represent pixel values.
 */
template<typename T>
class ImageBase : public Image {
    public:
        /**
         * @brief Default constructor.
         */
        ImageBase();

        /**
         * @brief Constructs the image from a given filename.
         * @param filename Name of the image file.
         */
        ImageBase(const std::string& filename);

        /**
         * @brief Rotates the image 90 degrees in the specified direction.
         * @param direction Either "left" or "right".
         */
        void rotate(const std::string& direction) override;

        /**
         * @brief Flips the image in the specified direction.
         * @param direction Either "top" or "left".
         */
        void flip(const std::string& direction) override;

        /**
         * @brief Writes all pixel data to the output stream.
         * @param ofs Output file stream.
         */
        void write_pixels(std::ofstream& ofs) const;

        /**
         * @brief Reads all pixel data from the input stream.
         * @param ifs Input file stream.
         */
        void read_pixels(std::ifstream& ifs);

        /**
         * @brief Reads a single pixel value from the stream.
         * @param is Input stream.
         * @return The read pixel value.
         */
        virtual T read_value(std::ifstream& is) const = 0;

        /**
         * @brief Virtual default destructor.
         */
        ~ImageBase() = default;
    protected:
        /**
         * @brief Pastes one pixel matrix into another at the specified position.
         * @param dest The destination pixel matrix.
         * @param src The source pixel matrix to paste.
         * @param pos_y Y-position in destination to paste into.
         * @param pos_x X-position in destination to paste into.
         * @return A new pixel matrix with the source pasted into destination.
         */
        std::vector<std::vector<T>> paste_pixels(const std::vector<std::vector<T>>& dest,
                                                 const std::vector<std::vector<T>>& src,
                                                 size_t pos_y, size_t pos_x);
    private:
        /**
         * @brief Transposes the matrix (rows become columns and vice versa).
         * @param array Matrix to transpose.
         */
        void transpose_matrix(std::vector<std::vector<T>>& array);

        /**
         * @brief Reverses the order of rows in the matrix (vertical flip).
         * @param array Matrix to reverse.
         */
        void reverse_rows(std::vector<std::vector<T>>& array);

        /**
         * @brief Reverses the order of columns in each row of the matrix (horizontal flip).
         * @param array Matrix to reverse.
         */
        void reverse_cols(std::vector<std::vector<T>>& array);
    protected:
        std::vector<std::vector<T>> pixels;
};

// Inline function definitions follow:

template<typename T>
inline ImageBase<T>::ImageBase() : Image() {}

template<typename T>
inline ImageBase<T>::ImageBase(const std::string& filename) : Image(filename) {}

template<typename T>
inline void ImageBase<T>::write_pixels(std::ofstream& ofs) const {
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            write_pixel(ofs, i, j);
            ofs << ' ';
        }
        ofs << '\n';
    }
}

template<typename T>
inline void ImageBase<T>::read_pixels(std::ifstream& ifs) {
    pixels.resize(height, std::vector<T>(width));
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            pixels[i][j] = read_value(ifs);
        }
    }
}

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
    } else {
        throw std::invalid_argument("Rotate expects <left | right> argument");
    }
    this->height = pixels.size();
    this->width = pixels[0].size();
}

template<typename T>
inline void ImageBase<T>::flip(const std::string& direction) {
    if (direction == "top") {
        reverse_rows(pixels);
    } else if (direction == "left") {
        reverse_cols(pixels);
    } else {
        throw std::runtime_error("Flip expects <top | left> argument.");
    }
    this->height = pixels.size();
    this->width = pixels[0].size();
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
            T temp = array[i][j];
            array[i][j] = array[i][array[i].size() - j - 1];
            array[i][array[i].size() - j - 1] = temp;
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