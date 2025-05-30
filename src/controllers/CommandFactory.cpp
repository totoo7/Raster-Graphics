#include "CommandFactory.hpp"

Command* CommandFactory::create(const std::string& cmd, const std::vector<std::string>& args, SessionManager* session_manager) {
    if (cmd == "help") {
        return new HelpCommand();
    } else if (cmd == "exit") {
        return new ExitCommand();
    } else if (cmd == "load") {
        return new LoadCommand(session_manager, args);
    } else if (cmd == "list") {
        return new ListCommand(session_manager->get_active());
    } else if (cmd == "negative") {
        return new NegativeCommand(session_manager->get_active());
    } else if (cmd == "monochrome") {
        return new MonochromeCommand(session_manager->get_active());
    } else if (cmd == "rotate") {
        return new RotateCommand(session_manager->get_active(), args[0]);
    } else if (cmd == "flip") {
        return new FlipCommand(session_manager->get_active(), args[0]);
    } else if (cmd == "save") {
        return new SaveCommand(session_manager->get_active());
    } else if (cmd == "saveas") {
        return new SaveAsCommand(session_manager->get_active(), args);
    } else if (cmd == "switch") {
        return new SwitchCommand(session_manager, std::stoi(args[0]));
    } else if (cmd == "add") {
        return new AddCommand(session_manager->get_active(), args[0]);
    }

    return nullptr;
}