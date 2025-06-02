#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "Command.hpp"
#include "SessionManager.hpp"

class AddCommand : public Command {
    public:
        AddCommand(Session* const session, const std::string& val);
        static size_t args_count() { return args; };
        std::string execute() override;
        bool is_undoable() const override { return false; };
    private:
        Session* const session;
        std::string file;
        static const size_t args = 0;
};

#endif