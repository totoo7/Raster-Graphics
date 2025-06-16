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
    std::cout << " <-- Welcome to Raster-Graphics --> \n";
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
    
    delete cmd;
    cmd = nullptr;
}