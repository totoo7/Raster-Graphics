#include "RedoCommand.hpp"

const size_t RedoCommand::args = 0;

RedoCommand::RedoCommand(Session* const session)
	: session(session) {}

std::string RedoCommand::execute() {
	if (session->get_redos().empty()) return "Nothing to redo.\n";
	session->redo();
	return "Redo was successful.\n";
}