#ifndef LIST_COMMAND_HPP
#define LIST_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

class ListCommand : public Command {
    public:
        ListCommand(Session* const session);
        static size_t args_count() { return args; };
        std::string execute() override;
        bool is_undoable() const override { return false; };
    private:
        Session* const session;
        static const size_t args = 0;
};

#endif