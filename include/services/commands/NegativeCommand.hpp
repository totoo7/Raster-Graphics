#ifndef NEGATIVE_COMMAND
#define NEGATIVE_COMMAND

#include "Command.hpp"
#include "Session.hpp"

class NegativeCommand : public Command {
public:
	NegativeCommand(Session* const session);
	static size_t args_count() { return args; };
	std::string execute() override;
	bool is_undoable() const override { return true; };
	Command* clone() override { return new NegativeCommand(*this); };
	void undo() override;
private:
	Session* const session;
	static const size_t args = 0;
};

#endif
