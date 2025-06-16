#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <fstream>

/**
 * @class Image
 * @brief Abstract base class for image representations.
 */
class Image {
    public:
        /**
         * @enum Type
         * @brief Enumeration for supported image formats.
         */
        enum class Type { PPM, PGM, PBM };
    public:
        /**
         * @brief Default constructor.
         */
        Image();

        /**
         * @brief Constructs an image from a file.
         * @param filename Name of the file to load.
         */
        Image(const std::string& filename);

        /**
         * @brief Converts the image to grayscale.
         */
        virtual void grayscale() = 0;

        /**
         * @brief Converts the image to monochrome.
         */
        virtual void monochrome() = 0;

        /**
         * @brief Inverts the colors of the image.
         */
        virtual void negative() = 0;

        /**
         * @brief Rotates the image in the given direction.
         * @param direction The direction to rotate ("left" or "right").
         */
        virtual void rotate(const std::string& direction) = 0;

        /**
         * @brief Flips the image in the given direction.
         * @param direction The direction to flip ("horizontal" or "vertical").
         */
        virtual void flip(const std::string& direction) = 0;

        /**
         * @brief Writes the image data to the provided output stream.
         * @param ofs Output file stream.
         */
        virtual void write_file(std::ofstream& ofs) const = 0;

        /**
         * @brief Writes a single pixel to the output stream.
         * @param ofs Output file stream.
         * @param i Row index.
         * @param j Column index.
         */
        virtual void write_pixel(std::ofstream& ofs, size_t i, size_t j) const = 0;

        /**
         * @brief Pastes this image into another image at the given position.
         * @param img_dest Destination image.
         * @param pos_x X-coordinate of paste position.
         * @param pos_y Y-coordinate of paste position.
         * @return Pointer to the updated destination image.
         */
        virtual Image* paste_into(Image* img_dest, size_t pos_x, size_t pos_y) = 0;

        /**
         * @brief Creates a deep copy of this image.
         * @return Pointer to the cloned image.
         */
        virtual Image* clone() const = 0;

        /**
         * @brief Sets the filename of the image.
         * @param val Filename to set.
         */
        void set_filename(const std::string& val);

        /**
         * @brief Gets the filename of the image.
         * @return The image filename.
         */
        std::string get_filename() const { return filename; };

        /**
         * @brief Gets the width of the image.
         * @return Image width in pixels.
         */
        size_t get_width() const { return width; };

        /**
         * @brief Gets the height of the image.
         * @return Image height in pixels.
         */
        size_t get_height() const { return height; };

        /**
         * @brief Gets the type of the image.
         * @return Image type (PPM, PGM, PBM).
         */
        Type get_type() const { return type; };

        /**
         * @brief Virtual destructor.
         */
        virtual ~Image() = default;
    private:
        /**
         * @brief Parses the header from an input file stream.
         * @param ifs Input file stream.
         */
        void parse_header(std::ifstream& ifs);
    protected:
        std::string filename;
        size_t width, height;
        Type type;
};

#endif