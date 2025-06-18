#include "NegativeCommand.hpp"

const size_t NegativeCommand::args = 0;

NegativeCommand::NegativeCommand(Session* const session) : session(session) {}

NegativeCommand::NegativeCommand(const NegativeCommand& rhs) : 
	session(rhs.session), SnapshotCommand(rhs) {}

std::string NegativeCommand::execute() {
	take_snapshot(session);
	session->negative();
	return "Negative was successful.\n";
}

void NegativeCommand::undo() {
	restore_snapshot(session);
}

void NegativeCommand::redo() {
	session->redo();
}