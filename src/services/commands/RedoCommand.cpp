#include "RedoCommand.hpp"

RedoCommand::RedoCommand(Session* const session)
	: session(session) {}

std::string RedoCommand::execute() {
	session->redo();
	return "Redo was successful.\n";
}