#include "ExitCommand.hpp"

const size_t ExitCommand::args = 0;

std::string ExitCommand::execute() {
    return "Exiting...\n";
}