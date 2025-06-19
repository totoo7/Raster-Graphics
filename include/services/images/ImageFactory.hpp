#ifndef IMAGE_FACTORY_HPP
#define IMAGE_FACTORY_HPP

#include "Image.hpp"

/**
 * @class ImageFactory
 * @brief Factory class to create Image objects based on file type.
 */
class ImageFactory {
    public:
        /**
         * @brief Creates an Image object based on the file extension.
         * @param filename The filename to create the image from.
         * @return Pointer to a newly created Image object, or nullptr if unsupported.
         */
        static Image* create_image(const std::string& filename);
    private:
         /**
         * @brief Deleted constructor to prevent instantiation of the factory.
         */
        ImageFactory() = delete;
        /**
         * @brief Deleted copy constructor to prevent copying.
         */
        ImageFactory(const ImageFactory& rhs) = delete;
        /**
         * @brief Deleted copy assignment operator to prevent assignment.
         */
        ImageFactory& operator=(const ImageFactory& rhs) = delete;
};

#endif