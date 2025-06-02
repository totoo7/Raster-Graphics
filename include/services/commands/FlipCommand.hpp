#ifndef FLIP_COMMAND_HPP
#define FLIP_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

class FlipCommand : public Command {
public:
	FlipCommand(Session* const session, const std::string& direction);
	static size_t get_args() { return args; };
	std::string execute() override;
	void undo() override;
	Command* clone() override { return new FlipCommand(*this); };
	bool is_undoable() const override { return true; };
private:
	Session* const session;
	std::string direction;
	static const size_t args = 1;
};

#endif