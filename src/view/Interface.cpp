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
        std::vector<std::string> args;
        args.push_back(input);
        if (cmd) {
            delete cmd;
            cmd = nullptr;
        }
        try {
            cmd = CommandFactory::create(args, &session_manager);
        } catch (...) {
            //! TODO APPROPRIATE HANDLE
        }
        out << cmd->execute();
        //!
    } while (dynamic_cast<ExitCommand*>(cmd) == nullptr);
    
    delete cmd;
    cmd = nullptr;
}