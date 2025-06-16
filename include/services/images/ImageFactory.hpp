#ifndef IMAGE_FACTORY_HPP
#define IMAGE_FACTORY_HPP

#include "Image.hpp"

class ImageFactory {
    public:
        static Image* create_image(std::string filename);
    private:
        ImageFactory() = delete;
        ImageFactory(const ImageFactory& rhs) = delete;
        ImageFactory& operator=(const ImageFactory& rhs) = delete;
};

#endif