#ifndef NEGATIVE_COMMAND
#define NEGATIVE_COMMAND

#include "Command.hpp"
#include "Session.hpp"
#include "SnapshotCommand.hpp"

/**
 * @brief Command to apply negative effect on images within a session.
 */
class NegativeCommand : public SnapshotCommand {
	public:
		/**
		 * @brief Constructs a NegativeCommand for the given session.
		 * @param session Pointer to the current session.
		 */
		NegativeCommand(Session* const session);

		/**
		 * @brief Copy constructor.
		 * @param rhs Reference to another NegativeCommand.
		 */
		NegativeCommand(const NegativeCommand& rhs);

		/**
		 * @brief Returns the required number of arguments for this command.
		 * @return Always returns 0.
		 */
		const size_t args_count() const override { return args; };

		/**
		 * @brief Executes the negative effect.
		 * @return Result message.
		 */
		std::string execute() override;

		/**
		 * @brief Indicates this command can be undone.
		 * @return True.
		 */
		bool is_undoable() const override { return true; };

		/**
		 * @brief Creates a copy of this command.
		 * @return Pointer to the cloned command.
		 */
		Command* clone() override { return new NegativeCommand(*this); };

		/**
		 * @brief Undoes the negative operation.
		 */
		void undo() override;

		/**
		 * @brief Redoes the negative operation.
		 */
		void redo() override;
	private:
		Session* const session;
		static const size_t args;
};

#endif