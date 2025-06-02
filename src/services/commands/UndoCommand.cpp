#include "UndoCommand.hpp"

UndoCommand::UndoCommand(Session* const session)
	: session(session) {}

std::string UndoCommand::execute() {
	if (session->history.empty()) return "Nothing to undo.\n";
	session->undo();
	return "Undo was successful.\n";
}

void UndoCommand::undo() {}