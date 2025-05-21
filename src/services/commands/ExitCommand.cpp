#include "ExitCommand.hpp"

size_t ExitCommand::args_count() {
    return args;
}

std::string ExitCommand::execute() {
    return "Exiting...\n";
}