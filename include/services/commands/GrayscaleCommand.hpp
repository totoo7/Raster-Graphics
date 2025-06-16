#ifndef GRAYSCALE_COMMAND
#define GRAYSCALE_COMMAND

#include "Command.hpp"
#include "Session.hpp"
#include "SnapshotCommand.hpp"

/**
 * @brief Command to convert all session images to grayscale.
 */
class GrayscaleCommand : public SnapshotCommand {
	public:
		/**
		 * @brief Constructs a GrayscaleCommand for the given session.
		 * @param session The session to apply the grayscale transformation to.
		 */
		GrayscaleCommand(Session* const session);

		/**
		 * @brief Copy constructor.
		 * @param rhs The command to copy.
		 */
		GrayscaleCommand(const GrayscaleCommand& rhs);

		/**
		 * @brief Returns the expected number of arguments.
		 * @return Argument count.
		 */
		static size_t args_count() { return args; };

		/**
		 * @brief Executes the grayscale operation on all session images.
		 * @return Result message of the operation.
		 */
		std::string execute() override;

		/**
		 * @brief Indicates whether this command supports undo.
		 * @return True.
		 */
		bool is_undoable() const override { return true; };

		/**
		 * @brief Creates a copy of this command.
		 * @return A new clone of the command.
		 */
		Command* clone() override { return new GrayscaleCommand(*this); };

		/**
		 * @brief Reverts the grayscale operation.
		 */
		void undo() override;

		/**
		 * @brief Reapplies the grayscale operation.
		 */
		void redo() override;
	private:
		Session* const session;
		static const size_t args = 0;
};

#endif