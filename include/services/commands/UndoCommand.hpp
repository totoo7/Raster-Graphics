#ifndef UNDO_COMMAND_HPP
#define UNDO_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

/**
 * @brief Command to undo the last executed undoable command in a session.
 */
class UndoCommand : public Command {
	public:
		/**
		 * @brief Constructs an UndoCommand for the given session.
		 * @param session Pointer to the session on which to perform the undo.
		 */
		UndoCommand(Session* const session);

		/**
		 * @brief Returns the number of required arguments.
		 * @return Always returns 0.
		 */
		const size_t args_count() const override { return args; };

		/**
		 * @brief Executes the undo operation.
		 * @return Result message.
		 */
		std::string execute() override;

		/**
		 * @brief No-op for this command since it is not itself undoable.
		 */
		void undo() override;

		/**
		 * @brief Indicates this command is not undoable.
		 * @return False.
		 */
		bool is_undoable() const override { return false; };
	private:
		Session* const session;
		static const size_t args;
};

#endif