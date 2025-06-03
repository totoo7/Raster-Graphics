#include "RedoCommand.hpp"

RedoCommand::RedoCommand(Session* const session)
	: session(session) {}

std::string RedoCommand::execute() {
	if (session->redos.empty()) return "Nothing to redo.\n";
	session->redo();
	return "Redo was successful.\n";
}