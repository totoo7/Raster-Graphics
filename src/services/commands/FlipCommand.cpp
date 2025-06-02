#include "FlipCommand.hpp"

FlipCommand::FlipCommand(Session* const session, const std::string& direction)
	: session(session), direction(direction) {
}

std::string FlipCommand::execute() {
	session->flip(direction);
	return "Flip was successful.\n";
}

void FlipCommand::undo() {
	session->flip(direction);
}