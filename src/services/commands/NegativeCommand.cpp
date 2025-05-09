#include "NegativeCommand.hpp"

NegativeCommand::NegativeCommand(Session* const session) : session(session) {}

size_t NegativeCommand::args_count() {
	return args;
}

std::string NegativeCommand::execute() {
	
    session->images[0]->negative();
	return "Negative was successful";
}
