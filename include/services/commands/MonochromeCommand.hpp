#ifndef MONOCHROME_COMMAND
#define MONOCHROME_COMMAND

#include "Command.hpp"
#include "SnapshotCommand.hpp"
#include "Session.hpp"

class MonochromeCommand : public SnapshotCommand {
public:
	MonochromeCommand(Session* const session);
	MonochromeCommand(const MonochromeCommand& rhs);
	static size_t args_count() { return args; };
	std::string execute() override;
	bool is_undoable() const override { return true; };
	Command* clone() override { return new MonochromeCommand(*this); };
	void undo() override;
private:
	Session* const session;
	static const size_t args = 0;
};

#endif
