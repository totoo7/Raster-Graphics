#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include <vector>
#include "SessionManager.hpp"

class CommandFactory {
    public:
        static Command* create(const std::string& cmd, const std::vector<std::string>& args, SessionManager* session_manager);
    private:
        CommandFactory() = delete;
        CommandFactory(const CommandFactory& rhs) = delete;
        CommandFactory& operator=(const CommandFactory& rhs) = delete;
};

#endif