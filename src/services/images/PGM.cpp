#include "PGM.hpp"
#include <iostream>

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



