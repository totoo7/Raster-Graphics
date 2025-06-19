#ifndef SAVE_AS_COMMAND_HPP
#define SAVE_AS_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

/**
 * @brief Command to save session images to new specified file names.
 */
class SaveAsCommand : public Command {
public:
	/**
	 * @brief Constructs a SaveAsCommand.
	 * @param session Pointer to the current session.
	 * @param files Vector of filenames to save the images as.
	 */
	SaveAsCommand(Session* const session, const std::vector<std::string>& files);
	/**
	 * @brief Returns the number of required arguments.
	 * @return Always returns -1.
	 */
	const size_t args_count() const override { return -1; };
	/**
	 * @brief Executes the save-as operation.
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
    std::vector<std::string> files;
};

#endif