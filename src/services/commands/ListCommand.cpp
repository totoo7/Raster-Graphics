#include "ListCommand.hpp"

const size_t ListCommand::args = 0;

ListCommand::ListCommand(Session* const session) : session(session) {}

std::string ListCommand::execute() {
    std::string res = "Active session with ID: " + std::to_string(session->get_id()) + "\nLoaded images:\n";
    for (size_t i = 0; i < session->get_images().size(); i++) {
        res += ' ';
        res += session->get_images()[i]->get_filename();
        res += '\n';
    }
    return res;
}

