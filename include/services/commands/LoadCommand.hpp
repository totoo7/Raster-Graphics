#ifndef LOAD_COMMAND_HPP
#define LOAD_COMMAND_HPP

#include "Command.hpp"
#include "SessionManager.hpp"

class LoadCommand : public Command {
    public:
        LoadCommand(SessionManager* const session_manager, const std::vector<std::string>& args);
        static size_t args_count() { return args; };
        std::string execute() override;
        bool is_undoable() const override { return false; };
        bool needs_session() const override { return false; };
    private:
        SessionManager* const session_manager;
        std::vector<std::string> files;
        static const size_t args = 0;
};

#endif