#ifndef SWITCH_COMMAND_HPP
#define SWITCH_COMMAND_HPP

#include "Command.hpp"
#include "SessionManager.hpp"

class SwitchCommand : public Command {
    public:
        SwitchCommand(SessionManager* const session_manager, size_t id);
        static size_t args_count() { return args; };
        std::string execute() override;
        bool is_undoable() const override { return false; };
    private:
        SessionManager* const session_manager;
        size_t id;
        static const size_t args = 0;
};

#endif