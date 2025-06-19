#include "RotateCommand.hpp"

const size_t RotateCommand::args = 1;

RotateCommand::RotateCommand(Session* const session, const std::string& direction)
	: session(session), direction(direction) {
}

std::string RotateCommand::execute() {
	session->rotate(direction);
	return "Rotate was successful.\n";
}

void RotateCommand::undo() {
	for (size_t i = 0; i < 3; i++) {
		session->rotate(direction);
	}
}

void RotateCommand::redo() {
	session->redo();
}