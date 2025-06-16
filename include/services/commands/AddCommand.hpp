#ifndef ADD_COMMAND_HPP
#define ADD_COMMAND_HPP

#include "Command.hpp"
#include "SessionManager.hpp"

/**
 * @brief Command to add a new image to the current session.
 */
class AddCommand : public Command {
    public:
		/**
		 * @brief Constructs an AddCommand with a target session and image file name.
		 * @param session Pointer to the session to add the image to.
		 * @param val Path to the image file.
		 */
        AddCommand(Session* const session, const std::string& val);

		/**
		 * @brief Returns the number of arguments expected by the command.
		 * @return Expected argument count.
		 */
        static size_t args_count() { return args; };

		/**
		 * @brief Executes the add command.
		 * @return Status message.
		 */
        std::string execute() override;

		/**
		 * @brief Indicates whether the command supports undo.
		 * @return False, as this command is not undoable.
		 */
        bool is_undoable() const override { return false; };
    private:
        Session* const session;
        std::string file;
        static const size_t args = 0;
};

#endif