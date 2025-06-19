#include "ImageFactory.hpp"
#include "PGM.hpp"
#include "PBM.hpp"
#include "PPM.hpp"
#include "Utilites.hpp"

Image* ImageFactory::create_image(const std::string& filename) {
    
    std::string type = UTILITIES::get_extension(filename);

    if (type == "pbm") {
        return new PBM(filename);
    } else if (type == "pgm") {
        return new PGM(filename);
    } else if (type == "ppm") {
        return new PPM(filename);
    }
    
    return nullptr;
}