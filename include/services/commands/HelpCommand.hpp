#ifndef HELP_COMMAND_HPP
#define HELP_COMMAND_HPP

#include "Command.hpp"

class HelpCommand : public Command {
    public:
        std::string execute() override;
        static size_t args_count() { return args; };
    private:
        static const size_t args = 0;
};

#endif