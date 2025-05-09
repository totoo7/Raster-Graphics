#ifndef NEGATIVE_COMMAND
#define NEGATIVE_COMMAND

#include "Command.hpp"
#include "Session.hpp"

class NegativeCommand : public Command {
public:
	NegativeCommand(Session* const session);
	static size_t args_count();
	std::string execute() override;
private:
	Session* const session;
	static const size_t args = 0;
};

#endif
