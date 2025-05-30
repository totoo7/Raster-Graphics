#include "Interface.hpp"
#include "Utilites.hpp"
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

        cmd = CommandFactory::create(command, args, &session_manager);
        if (!cmd) {
            std::cout << "Unknown command.\n";
            continue;
        }
        
        try {
            std::cout << cmd->execute();
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        } 
    } while (dynamic_cast<ExitCommand*>(cmd) == nullptr);
    
    delete cmd;
    cmd = nullptr;
}