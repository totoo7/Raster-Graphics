#include "CommandFactory.hpp"
#include "ExitCommand.hpp"
#include "HelpCommand.hpp"
#include "LoadCommand.hpp"
#include "ListCommand.hpp"
#include "NegativeCommand.hpp"
#include "MonochromeCommand.hpp"
#include "GrayscaleCommand.hpp"
#include "SaveCommand.hpp"
#include "SaveAsCommand.hpp"
#include "RotateCommand.hpp"
#include "FlipCommand.hpp"
#include "PasteCommand.hpp"
#include "SwitchCommand.hpp"
#include "AddCommand.hpp"
#include "UndoCommand.hpp"
#include "RedoCommand.hpp"

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
    } else if (cmd == "grayscale") {
        return new GrayscaleCommand(session_manager->get_active());
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
    } else if (cmd == "undo") {
        return new UndoCommand(session_manager->get_active());
    } else if (cmd == "redo") {
        return new RedoCommand(session_manager->get_active());
    } else if (cmd == "paste") {
        return new PasteCommand(session_manager->get_active(), args);
    }

    return nullptr;
}