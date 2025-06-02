#ifndef REDO_COMMAND_HPP
#define REDO_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

class RedoCommand : public Command {
    public:
        RedoCommand(Session* const session);
        static size_t get_args() { return args; };
        std::string execute() override;
        bool is_undoable() const override { return false; };
    private:
        Session* const session;
        static const size_t args = 0;
};

#endif