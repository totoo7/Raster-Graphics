#include "ImageFactory.hpp"
#include "PGM.hpp"
#include "PBM.hpp"
#include "PPM.hpp"
Image* ImageFactory::create_image(std::string filename) {
    std::string type = "";

    type.push_back(filename[filename.size() - 3]);
    type.push_back(filename[filename.size() - 2]);
    type.push_back(filename[filename.size() - 1]);


    if (type == "pbm") {
        return new PBM(filename);
    } else if (type == "pgm") {
        return new PGM(filename);
    } else if (type == "ppm") {
        return new PPM(filename);
    }
    
    return nullptr;
}