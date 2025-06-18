#ifndef ROTATE_COMMAND_HPP
#define ROTATE_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

/**
 * @brief Command to rotate all images in the session in a given direction.
 */
class RotateCommand : public Command {
	public:
		/**
		 * @brief Constructs a RotateCommand.
		 * @param session Pointer to the current session.
		 * @param direction Direction to rotate ("left" or "right").
		 */
		RotateCommand(Session* const session, const std::string& direction);

		/**
		 * @brief Returns the number of required arguments.
		 * @return Always returns 1.
		 */
		const size_t args_count() const override { return args; };

		/**
		 * @brief Executes the rotate operation.
		 * @return Result message.
		 */
		std::string execute() override;

		/**
		 * @brief Indicates that this command is undoable.
		 * @return True.
		 */
		bool is_undoable() const override { return true; };

		/**
		 * @brief Creates a deep copy of the command.
		 * @return Pointer to a new RotateCommand instance.
		 */
		Command* clone() override { return new RotateCommand(*this); };

		/**
		 * @brief Undoes the rotate operation.
		 */
		void undo() override;

		/**
		 * @brief Redoes the rotate operation.
		 */
		void redo() override;
	private:
		Session* const session;
		std::string direction;
		static const size_t args;
};

#endif