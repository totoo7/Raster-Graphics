#ifndef LOAD_COMMAND_HPP
#define LOAD_COMMAND_HPP

#include "Command.hpp"
#include "SessionManager.hpp"

class LoadCommand : public Command {
    public:
        LoadCommand(SessionManager* const session_manager, const std::string& filename);
        static size_t args_count();
        std::string execute() override;
    private:
        SessionManager* const session_manager;
        std::string filename;
        static const size_t args = 0;
};

#endif