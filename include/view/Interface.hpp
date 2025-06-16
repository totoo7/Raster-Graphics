#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Command.hpp"
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