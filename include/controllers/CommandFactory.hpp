#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include <vector>
#include "SessionManager.hpp"
#include "ExitCommand.hpp"
#include "HelpCommand.hpp"
#include "LoadCommand.hpp"
#include "ListCommand.hpp"
#include "NegativeCommand.hpp"
#include "MonochromeCommand.hpp"
#include "SaveCommand.hpp"
#include "RotateCommand.hpp"
#include "FlipCommand.hpp"

class CommandFactory {
    public:
        static Command* create(std::vector<std::string> args, SessionManager* session_manager);
    private:
        CommandFactory() = delete;
        CommandFactory(const CommandFactory& rhs) = delete;
        CommandFactory& operator=(const CommandFactory& rhs) = delete;
};

#endif