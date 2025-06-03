#include "Image.hpp"
#include <iostream>
#include "Utilites.hpp"
Image::Image() : width(0), height(0), format(Format::ASCII) {}

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
        format = Format::ASCII;
        type = Type::PBM;
    } else if (magic_number == "P2") {
        format = Format::ASCII;
        type = Type::PGM;
    } else if (magic_number == "P3") {
        format = Format::ASCII;
        type = Type::PPM;
    } else if (magic_number == "P4") {
        format = Format::BINARY;
        type = Type::PBM;
    } else if (magic_number == "P5") {
        format = Format::ASCII;
        type = Type::PGM;
    } else if (magic_number == "P6") {
        format = Format::ASCII;
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