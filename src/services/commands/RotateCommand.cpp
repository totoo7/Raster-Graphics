#include "RotateCommand.hpp"

RotateCommand::RotateCommand(Session* const session, const std::string& direction)
	: session(session), direction(direction) {
}

std::string RotateCommand::execute() {
	session->rotate(direction);
	return "Rotate was successful.\n";
}

void RotateCommand::undo() {
	
}