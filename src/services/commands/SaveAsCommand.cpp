#include "SaveAsCommand.hpp"

SaveAsCommand::SaveAsCommand(Session* const session, const std::vector<std::string>& files) : 
    session(session), files(files) {
}

std::string SaveAsCommand::execute() {
    if (files.size() != session->get_images().size()) {
        throw std::invalid_argument("Session contains " + std::to_string(session->get_images().size()) +
            " image(s), but " + std::to_string(files.size()) +
            " filename(s) were provided.");
    }
    session->save_as(files);
    std::string res = "Files ";
    for (size_t i = 0; i < files.size(); i++) {
        res += files[i];
        res += ' ';
    }

    res += "successfully saved.\n";
    return res;
}