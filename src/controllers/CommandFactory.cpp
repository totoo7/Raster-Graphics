#include "CommandFactory.hpp"

Command* CommandFactory::create(std::vector<std::string> args, SessionManager* session_manager) {
    std::string cmd = args[0];
    if (cmd == "help") {
        return new HelpCommand();
    } else if (cmd == "exit") {
        return new ExitCommand();
    } else if (cmd == "load") {
        return new LoadCommand(session_manager);
    } else if (cmd == "list") {
        return new ListCommand(session_manager->get_active());
    }
    return nullptr;
}