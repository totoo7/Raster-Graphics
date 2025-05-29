#include "SaveCommand.hpp"

SaveCommand::SaveCommand(Session* const session) : session(session) {}

std::string SaveCommand::execute() {
    session->save();
    return "Save was successful.\n";
}