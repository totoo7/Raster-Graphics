#include "SwitchCommand.hpp"

const size_t SwitchCommand::args = 1;


SwitchCommand::SwitchCommand(SessionManager* const session_manager, size_t id) : 
    session_manager(session_manager), id(id) {}

std::string SwitchCommand::execute() {
	session_manager->change(id);
    return "Active session is with ID: " + std::to_string(session_manager->get_active()->get_id()) + "\n";
}