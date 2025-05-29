#include "HelpCommand.hpp"

size_t HelpCommand::args_count() {
    return args;
}

std::string HelpCommand::execute() {
    std::string out;
    out += "-- All commands --\n";
    out += "> load :- Loads all arguments into one session. Commands are executed on every image in the session.\n";
    out += "> list :- Gives information on the current session.\n";
    out += "> negative :- Makes images in the active session negative.\n";
    out += "> exit :- Exits the program.\n";
    return out;
}