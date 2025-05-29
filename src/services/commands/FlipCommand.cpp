#include "FlipCommand.hpp"

FlipCommand::FlipCommand(Session* const session, std::string_view direction)
	: session(session), direction(direction) {
}

std::string FlipCommand::execute() {
	session->flip(direction);
	return "Flip was successful.\n";
}