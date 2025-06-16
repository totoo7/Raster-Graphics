#ifndef EXIT_COMMAND_HPP
#define EXIT_COMMAND_HPP

#include "Command.hpp"

/**
 * @brief Command to exit the application.
 */
class ExitCommand : public Command {
    public:
		/**
		 * @brief Executes the exit command.
		 * @return Exit status message.
		 */
        std::string execute() override;

		/**
		 * @brief Returns the number of arguments expected by the command.
		 * @return Expected argument count.
		 */
        static size_t args_count() { return args; };

		/**
		 * @brief Indicates that the command does not require a session.
		 * @return False.
		 */
        bool needs_session() const override { return false; };

		/**
		 * @brief Indicates whether the command supports undo.
		 * @return False.
		 */
        bool is_undoable() const override { return false; };
    private:
        static const size_t args = 0;
};

#endif