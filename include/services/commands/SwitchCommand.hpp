#ifndef SWITCH_COMMAND_HPP
#define SWITCH_COMMAND_HPP

#include "Command.hpp"
#include "SessionManager.hpp"

/**
 * @brief Command to switch to a different session by ID.
 */
class SwitchCommand : public Command {
    public:
        /**
         * @brief Constructs a SwitchCommand with a session manager and session ID.
         * @param session_manager Pointer to the session manager.
         * @param id ID of the session to switch to.
         */
        SwitchCommand(SessionManager* const session_manager, size_t id);

        /**
         * @brief Returns the number of required arguments.
         * @return Always returns 0.
         */
        static size_t args_count() { return args; };

        /**
         * @brief Executes the session switch operation.
         * @return Result message.
         */
        std::string execute() override;

        /**
         * @brief Indicates this command is not undoable.
         * @return False.
         */
        bool is_undoable() const override { return false; };
    private:
        SessionManager* const session_manager;
        size_t id;
        static const size_t args = 0;
};

#endif