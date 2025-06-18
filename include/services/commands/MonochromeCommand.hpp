#ifndef MONOCHROME_COMMAND
#define MONOCHROME_COMMAND

#include "Command.hpp"
#include "SnapshotCommand.hpp"
#include "Session.hpp"

/**
 * @brief Command to apply monochrome effect on images within a session.
 */
class MonochromeCommand : public SnapshotCommand {
	public:
		/**
		 * @brief Constructs a MonochromeCommand for the given session.
		 * @param session Pointer to the current session.
		 */
		MonochromeCommand(Session* const session);

		/**
		 * @brief Copy constructor.
		 * @param rhs Reference to another MonochromeCommand.
		 */
		MonochromeCommand(const MonochromeCommand& rhs);

		/**
		 * @brief Returns the required number of arguments for this command.
		 * @return Always returns 0.
		 */
		const size_t args_count() const override { return args; };

		/**
		 * @brief Executes the monochrome conversion.
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
		Command* clone() override { return new MonochromeCommand(*this); };

		/**
		 * @brief Undoes the monochrome operation.
		 */
		void undo() override;

		/**
		 * @brief Redoes the monochrome operation.
		 */
		void redo() override;
	private:
		Session* const session;
		static const size_t args;
};

#endif