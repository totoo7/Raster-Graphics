#include "HelpCommand.hpp"

size_t HelpCommand::args_count() {
    return args;
}

std::string HelpCommand::execute() {
    std::string out;
    out += "This is a help command :)\n";
    return out;
}