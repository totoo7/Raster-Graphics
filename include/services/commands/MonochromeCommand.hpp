#ifndef MONOCHROME_COMMAND
#define MONOCHROME_COMMAND

#include "Command.hpp"
#include "Session.hpp"

class MonochromeCommand : public Command {
public:
	MonochromeCommand(Session* const session);
	MonochromeCommand(const MonochromeCommand& rhs);
	static size_t args_count() { return args; };
	std::string execute() override;
	bool is_undoable() const override { return true; };
	Command* clone() override { return new MonochromeCommand(*this); };
	void undo() override;
	~MonochromeCommand();
private:
	Session* const session;
	std::vector<Image*> snapshots;
	static const size_t args = 0;
};

#endif
