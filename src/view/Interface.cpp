#include "Interface.hpp"
#include "Utilites.hpp"
Interface::Interface() : cmd(nullptr) {}

Interface& Interface::get_instance() {
    static Interface interface;
    return interface;
}

void Interface::run(std::istream& in, std::ostream& out) {
    std::string line;
    do {
        std::getline(in, line);
        if (line.empty()) continue;

        std::vector<std::string> args = UTILITIES::split(line);

        if (cmd) {
            delete cmd;
            cmd = nullptr;
        }

        cmd = CommandFactory::create(args, &session_manager);
        if (!cmd) {
            std::cout << "Unknown command.\n";
            continue;
        }
        
        try {
            out << cmd->execute();
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        } 
    } while (dynamic_cast<ExitCommand*>(cmd) == nullptr);
    
    delete cmd;
    cmd = nullptr;
}