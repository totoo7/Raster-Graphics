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
    for (size_t i = 0; i < height; ++i)
		for (size_t j = 0; j < width; ++j)
			pixels[i][j] = max_val - pixels[i][j];
}

void PGM::rotate(const std::string& direction) {
    //TODO
}

void PGM::flip(const std::string& direction) {
    //TODO
}

void PGM::write_file(std::ofstream& ofs) {
    ofs << "P2\n";
    ofs << width << " " << height << "\n";
    ofs << max_val << "\n";
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            ofs << pixels[i][j] << ' ';
        }
        ofs << '\n'; 
    }
    ofs.close();
}