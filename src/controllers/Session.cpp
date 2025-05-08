#include "Session.hpp"

int Session::current_id = 0;

Session::Session() : id(Session::current_id++) {}

const int Session::get_id() const {
    return id;
}