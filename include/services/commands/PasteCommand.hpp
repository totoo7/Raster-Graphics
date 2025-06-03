#ifndef PASTE_COMMAND_HPP
#define PASTE_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"
class PasteCommand : public Command {
	public:
		PasteCommand(Session* const session, const std::vector<std::string>& args);
		static size_t get_args() { return args_count; };
		std::string execute() override;
		bool is_undoable() const override { return false; };
	private:
		Image* collage(Image* img_src, Image* img_dest, size_t pos_x, size_t pos_y);
	private:
		Session* const session;
		std::vector<std::string> args;
		static const size_t args_count = 4;
};

#endif