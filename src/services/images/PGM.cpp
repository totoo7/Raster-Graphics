#include "PGM.hpp"
#include <iostream>
#include "Utilites.hpp"

PGM::PGM(const std::string& filename) : ImageBase(filename) {
    std::ifstream ifs(filename);
    if (!ifs) throw std::runtime_error("Cannot open file: " + filename);
    UTILITIES::skip_comments(ifs, 2);
    unsigned temp;
    ifs >> temp;
    max_val = temp;
    pixels.resize(height, std::vector<uint8_t>(width));
    UTILITIES::skip_comments(ifs);
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            ifs >> temp;
            pixels[i][j] = temp;
        }
    }
    ifs.close();
}

PGM::PGM(const PGM& rhs) : max_val(rhs.max_val) {
    pixels = rhs.pixels;
}

Image* PGM::clone() const {
    return new PGM(*this);
}

void PGM::grayscale() {
    return;
}

void PGM::monochrome() {
    for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			if (pixels[i][j] < max_val / 2) pixels[i][j] = 0;
            else pixels[i][j] = max_val;
        }
    }
}

void PGM::negative() {
    for (size_t i = 0; i < height; ++i)
		for (size_t j = 0; j < width; ++j)
			pixels[i][j] = max_val - pixels[i][j];
}

Image* PGM::paste_into(Image* img_dest, size_t pos_x, size_t pos_y) {
    PGM* res = static_cast<PGM*>(img_dest->clone());
    res->pixels = paste_pixels(res->pixels, this->pixels, pos_x, pos_y);
    res->width = res->pixels[0].size();
    res->height = res->pixels.size();
    return res;
}

void PGM::write_file(std::ofstream& ofs) {
    ofs << "P2\n";
    ofs << width << " " << height << "\n";
    ofs << static_cast<unsigned>(max_val) << "\n";
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            ofs << static_cast<unsigned>(pixels[i][j]) << ' ';
        }
        ofs << '\n'; 
    }
}