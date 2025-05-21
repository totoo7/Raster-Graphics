#include "SaveCommand.hpp"

SaveCommand::SaveCommand(Session* const session) : session(session) {}

size_t SaveCommand::args_count() {
    return args;
}

std::string SaveCommand::execute() {
    session->save();
    return "Save was successful.\n";
}