#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <fstream>

class Image {
    public:
        enum class Format { BINARY, ASCII };
        enum class Type { PPM, PGM, PBM };
    public:
        Image();
        Image(const std::string& filename);
        virtual void grayscale() = 0;
        virtual void monochrome() = 0;
        virtual void negative() = 0;
        virtual void rotate(const std::string& direction) = 0;
        virtual void flip(const std::string& direction) = 0;
        virtual void write_file(std::ofstream& ofs) const = 0;
        virtual void write_pixel(std::ofstream& ofs, size_t i, size_t j) const = 0;
        virtual Image* paste_into(Image* img_dest, size_t pos_x, size_t pos_y) = 0;
        virtual Image* clone() const = 0;
        void set_filename(const std::string& val);
        std::string get_filename() const { return filename; };
        size_t get_width() const { return width; };
        size_t get_height() const { return height; };
        Type get_type() const { return type; };
        Format get_format() const { return format; };
        virtual ~Image() = default;
    private:
        void parse_header(std::ifstream& ifs);
    protected:
        std::string filename;
        size_t width, height;
        Type type;
        Format format;
};

#endif