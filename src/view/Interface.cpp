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
        std::cin >> input;
        std::vector<std::string> args;
        args.push_back(input);
        cmd = CommandFactory::create(args);
        std::cout << cmd->execute();
        //!
    } while (dynamic_cast<ExitCommand*>(cmd) == nullptr);
}