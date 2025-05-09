#include "Session.hpp"

int Session::current_id = 0;

Session::Session() : id(Session::current_id++) {}

void Session::add_image(Image* image) {
    images.push_back(image);
}

const int Session::get_id() const {
    return id;
}