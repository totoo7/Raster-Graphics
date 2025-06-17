#include "Interface.hpp"

#include <iostream>
#include "Utilites.hpp"
#include "ExitCommand.hpp"
#include "CommandFactory.hpp"

Interface::Interface() : cmd(nullptr) {}

Interface& Interface::get_instance() {
    static Interface interface;
    return interface;
}

void Interface::run() {
    std::string line;
    std::cout << " <-- Welcome to Raster-Graphics --> \n Use 'help' command to check all available commands.\n";
    do {
        std::getline(std::cin, line);
        if (line.empty()) continue;

        std::vector<std::string> args = UTILITIES::split(line);
        std::string command = args[0];
        args.erase(args.begin());

        if (cmd) {
            delete cmd;
            cmd = nullptr;
        }

        try {
            cmd = CommandFactory::create(command, args, &session_manager);
            if (!cmd) {
                std::cout << "Error: Unknown command.\n";
                continue;
            }
            if (cmd->needs_session() && session_manager.get_active() == nullptr)
                throw std::runtime_error("This command needs active session.");

            std::cout << cmd->execute();
            if (cmd->is_undoable()) {
                Interface::get_instance().session_manager.get_active()->history.push_back(cmd->clone()); //!
                Interface::get_instance().session_manager.get_active()->redos.clear();
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
            delete cmd;
            cmd = nullptr;
        }
    } while (dynamic_cast<ExitCommand*>(cmd) == nullptr);

    std::vector<Session> sessions = session_manager.get_sessions();
    for (size_t i = 0; i < sessions.size(); i++) {
        if (sessions[i].has_unsaved_changes) {
            std::cout << "Session with ID: " << sessions[i].get_id() << " has unsaved work. Save it now (y/n)?\n";
            char answer;
            std::cin >> answer;
            session_manager.change(sessions[i].get_id());
            if (answer == 'y') 
                CommandFactory::create("save", {}, &session_manager)->execute();
        }
    }

    delete cmd;
    cmd = nullptr;
}