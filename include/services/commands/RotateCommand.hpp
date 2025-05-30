#ifndef ROTATE_COMMAND_HPP
#define ROTATE_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

class RotateCommand : public Command {
public:
	RotateCommand(Session* const session, const std::string& direction);
	static size_t get_args() { return args; };
	std::string execute() override;
private:
	Session* const session;
	std::string direction;
	static const size_t args = 1;
};

#endif