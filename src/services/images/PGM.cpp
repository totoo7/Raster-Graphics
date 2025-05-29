#include "PGM.hpp"
#include <iostream>
#include "Utilites.hpp"

PGM::PGM(const std::string& filename) : Image(filename) {
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

Image* PGM::clone() const {
    return new PGM(*this);
}

void PGM::grayscale() {
    return;
}

void PGM::monochrome() {
    //TODO
}

void PGM::negative() {
    for (size_t i = 0; i < height; ++i)
		for (size_t j = 0; j < width; ++j)
			pixels[i][j] = max_val - pixels[i][j];
}

void PGM::rotate(const std::string& direction) {
    if (direction == "left") {
        UTILITIES::transpose_matrix(pixels);
        UTILITIES::reverse_rows(pixels);
    } else if (direction == "right") {
        UTILITIES::transpose_matrix(pixels);
        UTILITIES::reverse_cols(pixels);
    }
}

void PGM::flip(const std::string& direction) {
    if (direction == "top") {
        UTILITIES::reverse_rows(pixels);
    } else if (direction == "left") {
        UTILITIES::reverse_cols(pixels);
    }
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