#include "GrayscaleCommand.hpp"

const size_t GrayscaleCommand::args = 0;

GrayscaleCommand::GrayscaleCommand(Session* const session) : session(session) {}

GrayscaleCommand::GrayscaleCommand(const GrayscaleCommand& rhs) : 
	session(rhs.session), SnapshotCommand(rhs) {}

std::string GrayscaleCommand::execute() {
	take_snapshot(session);
	session->grayscale();
	return "Grayscale was successful.\n";
}

void GrayscaleCommand::undo() {
	restore_snapshot(session);
}

void GrayscaleCommand::redo() {
	session->redo();
}