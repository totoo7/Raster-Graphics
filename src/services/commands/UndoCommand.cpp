#include "UndoCommand.hpp"

const size_t UndoCommand::args = 0;

UndoCommand::UndoCommand(Session* const session)
	: session(session) {}

std::string UndoCommand::execute() {
	if (session->get_history().empty()) return "Nothing to undo.\n";
	session->undo();
	return "Undo was successful.\n";
}

void UndoCommand::undo() {}