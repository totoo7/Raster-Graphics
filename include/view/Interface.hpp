#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include "ExitCommand.hpp"
#include "HelpCommand.hpp"
#include "CommandFactory.hpp"

class Interface {
    public:
        static Interface& get_instance();
        void run(std::istream& in = std::cin, std::ostream& out = std::cout);
    private:
        Interface();
        Interface(const Interface& rhs) = delete;
        Interface& operator=(const Interface& rhs) = delete;
    private:
        Command* cmd;
        
};

#endif