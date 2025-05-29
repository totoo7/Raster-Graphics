#ifndef MONOCHROME_COMMAND
#define MONOCHROME_COMMAND

#include "Command.hpp"
#include "Session.hpp"

class MonochromeCommand : public Command {
public:
	MonochromeCommand(Session* const session);
	static size_t args_count() { return args; };
	std::string execute() override;
private:
	Session* const session;
	static const size_t args = 0;
};

#endif
