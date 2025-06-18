#include "SaveCommand.hpp"

const size_t SaveCommand::args = 0;

SaveCommand::SaveCommand(Session* const session) : session(session) {}

std::string SaveCommand::execute() {
    session->save();
    return "Save was successful.\n";
}