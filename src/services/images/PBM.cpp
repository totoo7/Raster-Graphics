#include "PBM.hpp"

#include "Utilites.hpp"

PBM::PBM(const std::string& filename) : ImageBase(filename) {
    std::ifstream ifs(filename);
    if (!ifs) throw std::runtime_error("Cannot open file: " + filename);
    UTILITIES::skip_comments(ifs, 2);
    read_pixels(ifs);
    ifs.close();
}

PBM::PBM(const PBM& rhs)  {
    pixels = rhs.pixels;
}

Image* PBM::clone() const {
    return new PBM(*this);
}

void PBM::grayscale() {
    return;
}

void PBM::monochrome() {
    return;
}

void PBM::negative() {
    for (size_t i = 0; i < height; ++i)
		for (size_t j = 0; j < width; ++j)
			pixels[i][j] = !pixels[i][j];
}

Image* PBM::paste_into(Image* img_dest, size_t pos_x, size_t pos_y) {
    PBM* res = static_cast<PBM*>(img_dest->clone());
    res->pixels = paste_pixels(res->pixels, this->pixels, pos_x, pos_y);
    res->width = res->pixels[0].size();
    res->height = res->pixels.size();
    return res;
}

bool PBM::read_value(std::ifstream& ifs) const {
    bool val;
    ifs >> val;
    return val;
}

void PBM::write_pixel(std::ofstream& ofs, size_t i, size_t j) const {
    ofs << static_cast<bool>(pixels[i][j]);
}

void PBM::write_file(std::ofstream& ofs) const {
    ofs << "P1\n";
    ofs << width << " " << height << "\n";
    write_pixels(ofs);
}