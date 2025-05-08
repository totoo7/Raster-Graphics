#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include <vector>

#include "ExitCommand.hpp"
#include "HelpCommand.hpp"

class CommandFactory {
    public:
        static Command* create(std::vector<std::string> args);
    private:
        CommandFactory() = delete;
        CommandFactory(const CommandFactory& rhs) = delete;
        CommandFactory& operator=(const CommandFactory& rhs) = delete;
};

#endif