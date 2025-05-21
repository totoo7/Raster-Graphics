#include "NegativeCommand.hpp"

NegativeCommand::NegativeCommand(Session* const session) : session(session) {}

size_t NegativeCommand::args_count() {
	return args;
}

std::string NegativeCommand::execute() {
	
	for (size_t i = 0; i < session->images.size(); i++) {
		session->images[i]->negative();
	}
	return "Negative was successful.\n";
}
