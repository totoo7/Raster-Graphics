#ifndef IMAGE_FACTORY_HPP
#define IMAGE_FACTORY_HPP

#include "Image.hpp"
#include "PGM.hpp"

class ImageFactory {
    public:
        ImageFactory() = delete;
        ImageFactory(const ImageFactory& rhs) = delete;
        ImageFactory& operator=(const ImageFactory& rhs) = delete;
        static Image* create_image(std::string filename);
};

#endif