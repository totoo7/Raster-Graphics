#ifndef SAVE_COMMAND_HPP
#define SAVE_COMMAND_HPP

#include "Command.hpp"
#include "Session.hpp"

class SaveCommand : public Command {
public:
	SaveCommand(Session* const session);
	static size_t args_count() { return args; };
	std::string execute() override;
private:
	Session* const session;
	static const size_t args = 0;
};

#endif