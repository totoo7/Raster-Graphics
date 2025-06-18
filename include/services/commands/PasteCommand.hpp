#ifndef PASTE_COMMAND_HPP
#define PASTE_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

/**
 * @brief Command to paste one image into another at a given position.
 */
class PasteCommand : public Command {
	public:
		/**
		 * @brief Constructs a PasteCommand with the given session and arguments.
		 * @param session Pointer to the current session.
		 * @param args Vector of arguments (expected: source image index, destination image index, x, y).
		 */
		PasteCommand(Session* const session, const std::vector<std::string>& args);

		/**
		 * @brief Returns the number of required arguments for this command.
		 * @return Always returns 5.
		 */
		const size_t args_count() const override { return args; };

		/**
		 * @brief Executes the paste operation.
		 * @return Result message.
		 */
		std::string execute() override;

		/**
		 * @brief Indicates this command is not undoable.
		 * @return False.
		 */
		bool is_undoable() const override { return false; };
	private:
		/**
		 * @brief Performs the actual pasting of one image into another.
		 * @param img_src Source image.
		 * @param img_dest Destination image.
		 * @param pos_x X-coordinate for pasting.
		 * @param pos_y Y-coordinate for pasting.
		 * @return A new image with the pasted content.
		 */
		Image* collage(Image* img_src, Image* img_dest, size_t pos_x, size_t pos_y);
	private:
		Session* const session;
		std::vector<std::string> arguments;
		static const size_t args;
};

#endif