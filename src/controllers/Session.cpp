#include "Session.hpp"

int Session::current_id = 0;

Session::Session() : id(Session::current_id++) {}

Session::Session(const Session& rhs) {
    for (size_t i = 0; i < rhs.images.size(); i++) {
        images.push_back(rhs.images[i]->clone());
    }
    id = rhs.id;
}

Session& Session::operator=(const Session& rhs) {
    if (this == &rhs) return *this;
    for (Image* img : images) {
        delete img;
    }
    images.clear();
    for(size_t i = 0; i < rhs.images.size(); i++) {
        images.push_back(rhs.images[i]->clone());
    }
    return*this;
}

void Session::add_image(Image* image) {
    images.push_back(image);
}

void Session::save() {
    for (size_t i = 0; i < images.size(); i++) {
        std::ofstream ofs(images[i]->get_filename());
        images[i]->write_file(ofs);
        ofs.close();
    }
}

void Session::rotate(const std::string& direction) {
    for (size_t i = 0; i < images.size(); i++) {
        images[i]->rotate(direction);
    }
}

void Session::flip(const std::string& direction) {
    for (size_t i = 0; i < images.size(); i++) {
        images[i]->flip(direction);
    }
}

const int Session::get_id() const {
    return id;
}

Session::~Session() {
    for (Image* img : images) {
        delete img;
    }
}