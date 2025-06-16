#ifndef SAVE_COMMAND_HPP
#define SAVE_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

/**
 * @brief Command to save all images in the current session to the day-hour-minute format.
 */
class SaveCommand : public Command {
public:
	/**
	 * @brief Constructs a SaveCommand.
	 * @param session Pointer to the current session.
	 */
	SaveCommand(Session* const session);

	/**
	 * @brief Returns the number of required arguments.
	 * @return Always returns 0.
	 */
	static size_t args_count() { return args; };

	/**
	 * @brief Executes the save operation.
	 * @return Result message.
	 */
	std::string execute() override;

	/**
	 * @brief Indicates this command is not undoable.
	 * @return False.
	 */
	bool is_undoable() const override { return false; };
private:
	Session* const session;
	static const size_t args = 0;
};

#endif