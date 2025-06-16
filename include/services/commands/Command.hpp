#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

/**
 * @brief Abstract base class representing a command in the system.
 * 
 * Defines the interface for all commands, including execution, undo/redo,
 * and cloning behavior.
 */
class Command {
    public:
		/**
		 * @brief Executes the command.
		 * @return A message indicating the result of execution.
		 */
        virtual std::string execute() = 0;

		/**
		 * @brief Checks if the command supports undo.
		 * @return True if undoable, false otherwise.
		 */
        virtual bool is_undoable() const = 0;

		/**
		 * @brief Checks if the command requires an active session.
		 * @return True if a session is needed, false by default.
		 */
        virtual bool needs_session() const { return true; };

		/**
		 * @brief Undoes the command operation.
		 */
        virtual void undo();

		/**
		 * @brief Redoes the command operation.
		 */
        virtual void redo();

		/**
		 * @brief Clones the command.
		 * @return A new instance (copy) of the command, or nullptr if not supported.
		 */
        virtual Command* clone() { return nullptr; };

		/**
		 * @brief Gets the number of arguments required by the command.
		 * @return Number of arguments.
		 */
        static size_t args_count();

		/**
		 * @brief Virtual destructor.
		 */
        virtual ~Command() = default;
    private:
        static const size_t args = 0;
};

#endif