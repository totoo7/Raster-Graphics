#include "MonochromeCommand.hpp"

MonochromeCommand::MonochromeCommand(Session* const session) : session(session) {}

MonochromeCommand::MonochromeCommand(const MonochromeCommand& rhs) : 
	session(rhs.session), SnapshotCommand(rhs) {}

std::string MonochromeCommand::execute() {
	take_snapshot(session);
	session->monochrome();
	return "Monochrome was successful.\n";
}

void MonochromeCommand::undo() {
	restore_snapshot(session);
}