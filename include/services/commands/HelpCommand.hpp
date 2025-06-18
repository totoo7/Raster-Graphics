#ifndef HELP_COMMAND_HPP
#define HELP_COMMAND_HPP

#include "Command.hpp"

/**
 * @brief Command that displays help information about available commands.
 */
class HelpCommand : public Command {
    public:
        /**
         * @brief Executes the help command, returning a list of supported commands.
         * @return Help message as a string.
         */
        std::string execute() override;

        /**
         * @brief Returns the expected number of arguments.
         * @return Argument count.
         */
        const size_t args_count() const override { return args; };

        /**
         * @brief Indicates that this command cannot be undone.
         * @return False.
         */
        bool is_undoable() const override { return false; };

        /**
         * @brief Indicates that this command does not require an active session.
         * @return False.
         */
        bool needs_session() const override { return false; };
    private:
        static const size_t args;
};

#endif