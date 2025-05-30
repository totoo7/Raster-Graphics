#include "AddCommand.hpp"
#include "ImageFactory.hpp"
#include <fstream>

AddCommand::AddCommand(Session* const session, const std::string& val) : session(session), file(val) {}

std::string AddCommand::execute() {
    std::ifstream ifs(file);
    if (!ifs) throw std::invalid_argument("File \"" + file + "\" didn't open correctly");
    ifs.close();

    Image* image = ImageFactory::create_image(file);
    if (!image)
            throw std::runtime_error("Image creation failed for \"" + file + "\"");
    
    session->add_image(image);
    return "Image added successfully.\n";
}

