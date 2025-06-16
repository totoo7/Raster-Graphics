#include "Image.hpp"
#include <iostream>
#include "Utilites.hpp"
Image::Image() : width(0), height(0) {}

Image::Image(const std::string& filename) : filename(filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) throw std::runtime_error("Cannot open file: " + filename);
    parse_header(ifs);
    ifs.close();
}

void Image::parse_header(std::ifstream& ifs) {
    std::string magic_number;
    UTILITIES::skip_comments(ifs);
    ifs >> magic_number;

    if (magic_number == "P1") {
        type = Type::PBM;
    } else if (magic_number == "P2") {
        type = Type::PGM;
    } else if (magic_number == "P3") {
        type = Type::PPM;
    } else {
        throw std::invalid_argument("Uknown netpbm file type.");
    }
    UTILITIES::skip_comments(ifs);
    ifs >> width >> height;
}

void Image::set_filename(const std::string& filename) {
    this->filename = filename;
}