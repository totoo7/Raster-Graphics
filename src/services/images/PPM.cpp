#include "PPM.hpp"
#include "Utilites.hpp"

PPM::PPM(const std::string& filename) : ImageBase(filename) {
    std::ifstream ifs(filename);
    if (!ifs) throw std::runtime_error("Cannot open file: " + filename);
    UTILITIES::skip_comments(ifs, 2);
    unsigned temp;
    ifs >> temp;
    max_val = temp;
    UTILITIES::skip_comments(ifs);
    read_pixels(ifs);
    ifs.close();
}

PPM::PPM(const PPM& rhs) : ImageBase(rhs), max_val(rhs.max_val) {
    pixels = rhs.pixels;
}

Image* PPM::clone() const {
    return new PPM(*this);
}

void PPM::grayscale() {
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            RGB& pixel = pixels[i][j];
            uint8_t gray = static_cast<uint8_t>(
                0.299 * pixel.red + 0.587 * pixel.green + 0.114 * pixel.blue
            );
            pixel.red = pixel.green = pixel.blue = gray;
        }
    }
}

void PPM::monochrome() {
    const uint8_t threshold = 128;

    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            RGB& pixel = pixels[i][j];
            uint8_t mono = static_cast<uint8_t>(
                0.2125 * pixel.red + 0.7154 * pixel.green + 0.0721 * pixel.blue
            );

            if (mono < threshold) {
                pixel = {0, 0, 0};
            } else {
                pixel = {255, 255, 255};
            }
        }
    }
}

void PPM::negative() {
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            RGB& pixel = pixels[i][j];
            pixel.red = max_val - pixel.red;
            pixel.green = max_val - pixel.green;
            pixel.blue = max_val - pixel.blue;
        }
    }
}

Image* PPM::paste_into(Image* img_dest, size_t pos_x, size_t pos_y) {
    PPM* res = static_cast<PPM*>(img_dest->clone());
    res->pixels = paste_pixels(res->pixels, this->pixels, pos_x, pos_y);
    res->width = res->pixels[0].size();
    res->height = res->pixels.size();
    return res;
}

RGB PPM::read_value(std::ifstream& is) const {
    unsigned r, g, b;
    is >> r >> g >> b;
    RGB pixel;
    pixel.red = static_cast<uint8_t>(r);
    pixel.green = static_cast<uint8_t>(g);
    pixel.blue = static_cast<uint8_t>(b);
    return pixel;
}

void PPM::write_pixel(std::ofstream& ofs, size_t i, size_t j) const {
    ofs << static_cast<unsigned>(pixels[i][j].red) << ' '
        << static_cast<unsigned>(pixels[i][j].green) << ' '
        << static_cast<unsigned>(pixels[i][j].blue) << ' ';
}

void PPM::write_file(std::ofstream& ofs) const {
    ofs << "P3\n";
    ofs << width << " " << height << "\n";
    ofs << static_cast<unsigned>(max_val) << "\n";
    write_pixels(ofs);
}