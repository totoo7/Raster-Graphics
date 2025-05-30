#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include "CommandFactory.hpp"
#include "SessionManager.hpp"

class Interface {
    public:
        static Interface& get_instance();
        void run();
    private:
        Interface();
        Interface(const Interface& rhs) = delete;
        Interface& operator=(const Interface& rhs) = delete;
    private:
        Command* cmd;
        SessionManager session_manager;
};

#endif