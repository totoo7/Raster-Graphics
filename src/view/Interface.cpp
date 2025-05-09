#include "Interface.hpp"

Interface::Interface() : cmd(nullptr) {}

Interface& Interface::get_instance() {
    static Interface interface;
    return interface;
}

void Interface::run(std::istream& in, std::ostream& out) {
    do {
        //! FOR TESTING PURPOSES 
        std::string input;
        in >> input;
        std::string filename;
        in >> filename;
        std::vector<std::string> args;
        args.push_back(input);
        args.push_back(filename);
        if (cmd) {
            delete cmd;
            cmd = nullptr;
        }
        cmd = CommandFactory::create(args, &session_manager);
        if (!cmd) {
            out << "Unknown command.";
        }
        //! TODO APPROPRIATE HANDLE
        out << cmd->execute();
        //!
    } while (dynamic_cast<ExitCommand*>(cmd) == nullptr);
    
    delete cmd;
    cmd = nullptr;
}