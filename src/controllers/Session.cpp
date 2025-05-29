#include "Session.hpp"

int Session::current_id = 0;

Session::Session() : id(Session::current_id++) {}

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

const int Session::get_id() const {
    return id;
}

Session::~Session() {
    for (Image* img : images) {
        delete img;
    }
}