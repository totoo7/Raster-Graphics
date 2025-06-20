#include "PasteCommand.hpp"
#include "ImageFactory.hpp"

const size_t PasteCommand::args = 5;

PasteCommand::PasteCommand(Session* const session, const std::vector<std::string>& args) 
    : session(session), arguments(args) {}

std::string PasteCommand::execute() {
    if (arguments.size() != 5) return "Invalid arguments count.\n";
    Image* img_src = ImageFactory::create_image(arguments[0]);
    Image* img_dest = ImageFactory::create_image(arguments[1]);
    if (!img_src || !img_dest) 
        throw std::runtime_error("Paste image creation failed.");
    
    size_t pos_x = std::stoi(arguments[2]);
    size_t pos_y = std::stoi(arguments[3]);
    std::string filename = arguments[4];

    Image* res = collage(img_src, img_dest, pos_x, pos_y);
    
    delete img_src;
    delete img_dest;

    res->set_filename(filename);
    

    session->add_image(res);
    std::ofstream ofs(res->get_filename());
    if (!ofs) throw std::runtime_error("Image creation failed for \"" + res->get_filename() + "\"");
    
    res->write_file(ofs);
    ofs.close();

    return "Paste was successful\n";
}

Image* PasteCommand::collage(Image* img_src, Image* img_dest, size_t pos_x, size_t pos_y) {
    if (img_src->get_type() != img_dest->get_type()) 
        throw std::runtime_error("Can't paste incompatible images.");
    return img_src->paste_into(img_dest, pos_x, pos_y);
}