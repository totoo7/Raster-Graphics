#ifndef PBM_HPP
#define PBM_HPP

#include "ImageBase.hpp"

/**
 * @class PBM
 * @brief Class representing a PBM (Portable Bitmap) image.
 * 
 * Inherits from ImageBase specialized with bool to represent pixels.
 */
class PBM : public ImageBase<bool> {
    public:
        /**
         * @brief Default constructor.
         */
        PBM() = default;

        /**
         * @brief Constructs a PBM image by loading from a file.
         * @param filename The path to the PBM file.
         */
        PBM(const std::string& filename);

        /**
         * @brief Copy constructor.
         * @param rhs The PBM object to copy from.
         */
        PBM(const PBM& rhs);

        /**
         * @brief Converts the image to grayscale. For PBM, typically no effect.
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
         * @brief Pastes this image into another image at given position.
         * @param img_dest Destination image pointer.
         * @param pos_x X position to paste at.
         * @param pos_y Y position to paste at.
         * @return Pointer to the resulting image.
         */
        Image* paste_into(Image* img_dest, size_t pos_x, size_t pos_y) override;

        /**
         * @brief Writes the PBM image to an output file stream.
         * @param ofs Output file stream to write to.
         */
        void write_file(std::ofstream& ofs) const override;

        /**
         * @brief Writes a single pixel to an output file stream.
         * @param ofs Output file stream.
         * @param i Row index.
         * @param j Column index.
         */
        void write_pixel(std::ofstream& ofs, size_t i, size_t j) const override;

        /**
         * @brief Reads a pixel value from an input file stream.
         * @param is Input file stream.
         * @return The read pixel value as bool.
         */
        bool read_value(std::ifstream& is) const override;

        /**
         * @brief Creates a deep copy of the image.
         * @return Pointer to the cloned Image object.
         */
        Image* clone() const override;
};

#endif