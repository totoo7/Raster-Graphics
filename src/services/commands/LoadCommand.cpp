#include "LoadCommand.hpp"
#include <iostream>
#include "ImageFactory.hpp"

LoadCommand::LoadCommand(SessionManager* const session_manager, const std::string& filename) : 
    session_manager(session_manager), filename(filename) {}

size_t LoadCommand::args_count() {
	return args;
}

std::string LoadCommand::execute() {
	std::ifstream ifs(filename);

	if (!ifs) throw std::invalid_argument("File \"" + filename + "\" didn't open correctly");

	Image* image = ImageFactory::create_image(filename);

	if (!image)
		throw std::runtime_error("Image creation failed");

	session_manager->add(Session());
	session_manager->get_active()->add_image(image);

	ifs.close();
	return "Created session " + std::to_string(session_manager->get_active()->get_id()) + " successfully.\n"; 
}