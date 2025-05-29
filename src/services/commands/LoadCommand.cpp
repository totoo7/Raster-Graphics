#include "LoadCommand.hpp"
#include <iostream>
#include "ImageFactory.hpp"

LoadCommand::LoadCommand(SessionManager* const session_manager, std::vector<std::string> args) : 
    session_manager(session_manager), files(args) {}

std::string LoadCommand::execute() {
	std::vector<Image*> loaded_images;

    for (size_t i = 1; i < files.size(); ++i) {
        std::ifstream ifs(files[i]);
        if (!ifs)
            throw std::invalid_argument("File \"" + files[i] + "\" didn't open correctly");
        ifs.close();

        Image* image = ImageFactory::create_image(files[i]);
        if (!image)
            throw std::runtime_error("Image creation failed for \"" + files[i] + "\"");

        loaded_images.push_back(image);
    }

    session_manager->add(Session());
    Session* session = session_manager->get_active();

    for (Image* img : loaded_images) {
        session->add_image(img);
    }

    return "Session with ID: " + std::to_string(session->get_id()) + " started.\n";
}