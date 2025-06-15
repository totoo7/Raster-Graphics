#include "PBM.hpp"

#include "Utilites.hpp"

PBM::PBM(const std::string& filename) : ImageBase(filename) {
    std::ifstream ifs(filename);
    if (!ifs) throw std::runtime_error("Cannot open file: " + filename);
    UTILITIES::skip_comments(ifs, 2);
    unsigned temp;
    ifs >> temp;
    pixels.resize(height, std::vector<bool>(width));
    UTILITIES::skip_comments(ifs);
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            ifs >> temp;
            pixels[i][j] = temp;
        }
    }
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
    //TODO
}

void PBM::negative() {
    //TODO
}

Image* PBM::paste_into(Image* img_dest, size_t pos_x, size_t pos_y) {
    PBM* res = static_cast<PBM*>(img_dest->clone());
    res->pixels = paste_pixels(res->pixels, this->pixels, pos_x, pos_y);
    res->width = res->pixels[0].size();
    res->height = res->pixels.size();
    return res;
}


//! MOVE THIS TO IMAGE BASE
void PBM::write_file(std::ofstream& ofs) {
    ofs << "P1\n";
    ofs << width << " " << height << "\n";
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            ofs << static_cast<bool>(pixels[i][j]) << ' ';
        }
        ofs << '\n'; 
    }
}