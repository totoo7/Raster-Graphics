#ifndef REDO_COMMAND_HPP
#define REDO_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

/**
 * @brief Command to redo the last undone operation in a session.
 */
class RedoCommand : public Command {
    public:
        /**
         * @brief Constructs a RedoCommand for the given session.
         * @param session Pointer to the current session.
         */
        RedoCommand(Session* const session);

        /**
         * @brief Returns the number of required arguments for this command.
         * @return Always returns 0.
         */
        const size_t args_count() const override { return args; };

        /**
         * @brief Executes the redo operation.
         * @return Result message.
         */
        std::string execute() override;

        /**
         * @brief Indicates this command cannot be undone.
         * @return False.
         */
        bool is_undoable() const override { return false; };
    private:
        Session* const session;
        static const size_t args;
};

#endif