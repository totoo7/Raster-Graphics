#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <fstream>

class Image {
    public:
        Image();
        Image(const std::string& filename);
        virtual void grayscale() = 0;
        virtual void monochrome() = 0;
        virtual void negative() = 0;
        virtual void rotate(const std::string& direction) = 0;
        virtual void flip(const std::string& direction) = 0;
        virtual void write_file(std::ofstream& ofs) = 0;
        virtual Image* clone() const = 0;
        std::string get_filename() const { return filename; };
        virtual ~Image() = default;
    private:
        void parse_header(std::ifstream& ifs);
    protected:
        enum class Format { BINARY, ASCII };
        enum class Type { PPM, PGM, PBM };
    protected:
        std::string filename;
        size_t width, height;
        Type type;
        Format format;
};

#endif