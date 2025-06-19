#include "Session.hpp"
#include "Utilites.hpp"
#include <ctime>

int Session::current_id = 0;

Session::Session() : id(Session::current_id++), has_unsaved_changes(false) {}

Session::Session(const Session& rhs) : has_unsaved_changes(rhs.has_unsaved_changes) {
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
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);

    char timestamp[16];
    std::strftime(timestamp, sizeof(timestamp), "%d-%H-%M", local_time);

    for (size_t i = 0; i < images.size(); i++) {
        std::string original = images[i]->get_filename();

        size_t dot_pos = original.find_last_of('.');
        std::string base = (dot_pos != std::string::npos) ? original.substr(0, dot_pos) : original;
        std::string ext = (dot_pos != std::string::npos) ? original.substr(dot_pos) : "";

        std::string new_filename = base + "_" + timestamp + ext;

        std::ofstream ofs(new_filename);
        if (!ofs) throw std::runtime_error("Save failed failed for \"" + new_filename + "\"");
        
        images[i]->write_file(ofs);
        ofs.close();
    }
    has_unsaved_changes = false;
}

void Session::saveAs(const std::vector<std::string>& files) {
    for(size_t i = 0; i < files.size(); i++) {
        if (images[i]->type_str() != UTILITIES::get_extension(files[i])) 
            throw std::invalid_argument("Mismatch in extensions.");
        
        std::ofstream ofs(files[i]);
        if (!ofs) throw std::runtime_error("Save failed for \"" + files[i] + "\"");
        images[i]->write_file(ofs);
        ofs.close();
    }
    has_unsaved_changes = false;
}

void Session::rotate(const std::string& direction) {
    for (size_t i = 0; i < images.size(); i++)
        images[i]->rotate(direction);
    
    has_unsaved_changes = true;
}

void Session::monochrome() {
    for (size_t i = 0; i < images.size(); i++)
        images[i]->monochrome();
    has_unsaved_changes = true;
}

void Session::negative() {
    for (size_t i = 0; i < images.size(); i++) 
		images[i]->negative();
    has_unsaved_changes = true;
}

void Session::grayscale() {
    for (size_t i = 0; i < images.size(); i++) 
		images[i]->grayscale();
    has_unsaved_changes = true;
}

void Session::flip(const std::string& direction) {
    for (size_t i = 0; i < images.size(); i++)
        images[i]->flip(direction);
    has_unsaved_changes = true;
}

const int Session::get_id() const {
    return id;
}

void Session::undo() {
    Command* cmd = history.back();
    history.pop_back();
    cmd->undo();
    redos.push_back(cmd->clone());
    delete cmd;
}

void Session::redo() {
    Command* cmd = redos.back();
    redos.pop_back();
    cmd->execute();
    history.push_back(cmd->clone());
    delete cmd;
}

Session::~Session() {
    for (Image* img : images) {
        delete img;
    }
    for (Command* cmd : history) {
        delete cmd;
    }
    for (Command* redo : redos) {
        delete redo;
    }
}