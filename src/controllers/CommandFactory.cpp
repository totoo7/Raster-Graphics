#include "CommandFactory.hpp"

Command* CommandFactory::create(std::vector<std::string> args) {
    std::string cmd = args[0];
    if (cmd == "help") {
        return new HelpCommand();
    } else if (cmd == "exit") {
        return new ExitCommand();
    }
}