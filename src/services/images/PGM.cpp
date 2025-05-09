#include "PGM.hpp"
#include <iostream>

PGM::PGM(const std::string& filename) : Image(filename) {
    std::ifstream ifs(filename);
    if (!ifs) throw std::runtime_error("Cannot open file: " + filename);
    std::string line;
    std::getline(ifs, line);
    std::getline(ifs, line);
    ifs >> max_val;
    pixels.resize(width, std::vector<unsigned int>(height));
    for (size_t i = 0; i < width; i++) {
        for (size_t j = 0; j < height; j++) {
            ifs >> pixels[i][j];
        }
    }
    ifs.close();
}

Image* PGM::clone() const {
    return new PGM(*this);
}

void PGM::grayscale() {
    //TODO
}

void PGM::monochrome() {
    //TODO
}

void PGM::negative() {
    //TODO
}

void PGM::rotate(const std::string& direction) {
    //TODO
}

void PGM::flip(const std::string& direction) {
    //TODO
}



