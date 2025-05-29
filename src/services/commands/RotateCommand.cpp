#include "RotateCommand.hpp"

RotateCommand::RotateCommand(Session* const session, std::string_view direction)
	: session(session), direction(direction) {
}

std::string RotateCommand::execute() {
	session->rotate(direction);
	return "Rotate was successful.\n";
}