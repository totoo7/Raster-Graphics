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
#include "SaveAsCommand.hpp"
#include "RotateCommand.hpp"
#include "FlipCommand.hpp"
#include "PasteCommand.hpp"
#include "SwitchCommand.hpp"
#include "AddCommand.hpp"
#include "UndoCommand.hpp"
#include "RedoCommand.hpp"

class CommandFactory {
    public:
        static Command* create(const std::string& cmd, const std::vector<std::string>& args, SessionManager* session_manager);
    private:
        CommandFactory() = delete;
        CommandFactory(const CommandFactory& rhs) = delete;
        CommandFactory& operator=(const CommandFactory& rhs) = delete;
};

#endif