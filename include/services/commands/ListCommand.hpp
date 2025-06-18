#ifndef LIST_COMMAND_HPP
#define LIST_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

/**
 * @brief Command that lists details about the active session and its images.
 */
class ListCommand : public Command {
    public:
        /**
         * @brief Constructs a ListCommand with a pointer to the active session.
         * @param session Pointer to the active session.
         */
        ListCommand(Session* const session);

        /**
         * @brief Returns the expected number of arguments for this command.
         * @return Argument count (always 0).
         */
        const size_t args_count() const override { return args; };

        /**
         * @brief Executes the command, returning information about the session.
         * @return A string with session details.
         */
        std::string execute() override;

        /**
         * @brief Indicates that this command cannot be undone.
         * @return False.
         */
        bool is_undoable() const override { return false; };
    private:
        Session* const session;
        static const size_t args;
};

#endif