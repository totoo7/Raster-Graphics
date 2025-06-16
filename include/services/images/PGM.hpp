#ifndef PGM_HPP
#define PGM_HPP

#include "ImageBase.hpp"
#include <cstdint>

/**
 * @class PGM
 * @brief Class representing a PGM (Portable Graymap) image.
 * 
 * Inherits from ImageBase specialized with uint8_t to represent grayscale pixels.
 */
class PGM : public ImageBase<uint8_t> {
    public:
        /**
         * @brief Default constructor.
         */
        PGM() = default;

        /**
         * @brief Constructs a PGM image by loading from a file.
         * @param filename The path to the PGM file.
         */
        PGM(const std::string& filename);

        /**
         * @brief Copy constructor.
         * @param rhs The PGM object to copy from.
         */
        PGM(const PGM& rhs);

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
         * @brief Writes the PGM image to an output file stream.
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
         * @return The read pixel value as uint8_t.
         */
        uint8_t read_value(std::ifstream& is) const override;

        /**
         * @brief Default destructor.
         */
        ~PGM() = default;
    private:
        uint8_t max_val;
};

#endif