#include "ListCommand.hpp"

ListCommand::ListCommand(Session* const session) : session(session) {}

size_t ListCommand::args_count() {
	return args;
}

std::string ListCommand::execute() {
    return std::to_string(session->get_id() + '\n');
}

