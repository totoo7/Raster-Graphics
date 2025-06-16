#ifndef GRAYSCALE_COMMAND
#define GRAYSCALE_COMMAND

#include "Command.hpp"
#include "Session.hpp"
#include "SnapshotCommand.hpp"

class GrayscaleCommand : public SnapshotCommand {
public:
	GrayscaleCommand(Session* const session);
	GrayscaleCommand(const GrayscaleCommand& rhs);
	static size_t args_count() { return args; };
	std::string execute() override;
	bool is_undoable() const override { return true; };
	Command* clone() override { return new GrayscaleCommand(*this); };
	void undo() override;
	void redo() override;
private:
	Session* const session;
	static const size_t args = 0;
};

#endif
