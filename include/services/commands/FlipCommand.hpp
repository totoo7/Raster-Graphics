#ifndef FLIP_COMMAND_HPP
#define FLIP_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

/**
 * @brief Command to flip all images in the session.
 */
class FlipCommand : public Command {
	public:
		/**
		 * @brief Constructs a new FlipCommand.
		 * @param session The session on which to operate.
		 * @param direction The direction to flip (e.g., "top" or "left").
		 */
		FlipCommand(Session* const session, const std::string& direction);

		/**
		 * @brief Returns the number of arguments required by the command.
		 * @return Number of expected arguments.
		 */
		static size_t get_args() { return args; };

		/**
		 * @brief Executes the flip command on the session images.
		 * @return Result message of the operation.
		 */
		std::string execute() override;

		/**
		 * @brief Creates a copy of the command.
		 * @return A clone of this command.
		 */
		Command* clone() override { return new FlipCommand(*this); };

		/**
		 * @brief Indicates whether the command supports undo.
		 * @return True.
		 */
		bool is_undoable() const override { return true; };

		/**
		 * @brief Undoes the flip operation.
		 */
		void undo() override;

		/**
		 * @brief Redoes the flip operation.
		 */
		void redo() override;
	private:
		Session* const session;
		std::string direction;
		static const size_t args = 1;
};

#endif