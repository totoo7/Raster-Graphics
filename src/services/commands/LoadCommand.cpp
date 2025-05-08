#include "LoadCommand.hpp"


LoadCommand::LoadCommand(SessionManager* const session_manager) : 
    session_manager(session_manager) {}

size_t LoadCommand::args_count() {
	return args;
}

std::string LoadCommand::execute() {
	session_manager->add(Session());
	return "Created session " + std::to_string(session_manager->get_active()->get_id()) + " successfully.\n";  
}