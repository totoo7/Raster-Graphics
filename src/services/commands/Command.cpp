#include "Command.hpp"

size_t Command::args_count() {
    return args;
}

void Command::undo() {}

void Command::redo() {}