#ifndef PPM_HPP
#define PPM_HPP

#include "ImageBase.hpp"
#include <cstdint>

/**
 * @struct RGB
 * @brief Represents a pixel in RGB color format.
 */
struct RGB {
    uint8_t red;   /**< Red channel */
    uint8_t green; /**< Green channel */
    uint8_t blue;  /**< Blue channel */
};

/**
 * @class PPM
 * @brief Class representing a PPM (Portable Pixmap) image.
 * 
 * Inherits from ImageBase specialized with RGB struct to represent color pixels.
 */
class PPM : public ImageBase<RGB> {
    public:
        /**
         * @brief Default constructor.
         */
        PPM() = default;

        /**
         * @brief Constructs a PPM image by loading from a file.
         * @param filename The path to the PPM file.
         */
        PPM(const std::string& filename);

        /**
         * @brief Copy constructor.
         * @param rhs The PPM object to copy from.
         */
        PPM(const PPM& rhs);

        /**
         * @brief Converts the image to grayscale.
         */
        void grayscale() override;

        /**
         * @brief Converts the image to monochrome.
         */
        void monochrome() override;

        /**
         * @brief Applies negative transformation to the image pixels.
         */
        void negative() override;

        /**
         * @brief Writes a single pixel to an output file stream.
         * @param ofs Output file stream.
         * @param i Row index.
         * @param j Column index.
         */
        void write_pixel(std::ofstream& ofs, size_t i, size_t j) const override;

        /**
         * @brief Pastes this image into another image at given position.
         * @param img_dest Destination image pointer.
         * @param pos_x X position to paste at.
         * @param pos_y Y position to paste at.
         * @return Pointer to the resulting image.
         */
        Image* paste_into(Image* img_dest, size_t pos_x, size_t pos_y) override;

        /**
         * @brief Writes the PPM image to an output file stream.
         * @param ofs Output file stream to write to.
         */
        void write_file(std::ofstream& ofs) const override;

        /**
         * @brief Creates a deep copy of the image.
         * @return Pointer to the cloned Image object.
         */
        Image* clone() const override;

        /**
         * @brief Reads a pixel value from an input file stream.
         * @param is Input file stream.
         * @return The read pixel value as RGB struct.
         */
        RGB read_value(std::ifstream& is) const override;

        /**
         * @brief Default destructor.
         */
        ~PPM() = default;
    private:
        uint8_t max_val;
};

#endif