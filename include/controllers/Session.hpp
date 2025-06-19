#ifndef SESSION_HPP
#define SESSION_HPP

#include <vector>
#include "Image.hpp"
#include "Command.hpp"

/**
 * @brief Represents an editing session that can hold and manipulate multiple images.
 * 
 * Each Session has a unique ID and maintains a history of commands for undo/redo functionality.
 */
class Session {
    public:
        /**
         * @brief Constructs a new Session and assigns it a unique ID.
         */
        Session();

        /**
         * @brief Copy constructor.
         * @param rhs Session to copy from.
         */
        Session(const Session& rhs);

        /**
         * @brief Copy assignment operator.
         * @param rhs Session to copy from.
         * @return Reference to this session.
         */
        Session& operator=(const Session& rhs);

        /**
         * @brief Gets the ID of the session.
         * @return The unique ID of the session.
         */
        const int get_id() const;

        /**
         * @brief Adds an image to the session.
         * @param image Pointer to the image to be added.
         */
        void add_image(Image* image);

        /**
         * @brief Rotates all images in the session in the specified direction.
         * @param direction Either "left" or "right".
         */
        void rotate(const std::string& direction);

        /**
         * @brief Flips all images in the session in the specified direction.
         * @param direction Either "horizontal" or "vertical".
         */
        void flip(const std::string& direction);

        /**
         * @brief Converts all images in the session to monochrome.
         */
        void monochrome();

        /**
         * @brief Converts all images in the session to their negative form.
         */
        void negative();

        /**
         * @brief Converts all images in the session to grayscale.
         */
        void grayscale();

        /**
         * @brief Saves all images in the session with day-hour-minute format.
         * @example If it is the 20th day and is 16:03 , the file "test.pgm" would be saved as "test_20-16-03.pgm"
         */
        void save();

        /**
         * @brief Saves all images to specified filenames.
         * @param files A vector of output filenames.
         */
        void save_as(const std::vector<std::string>& files);

        /**
         * @brief Undoes the last command applied to the session.
         */
        void undo();

        /**
         * @brief Redoes the last undone command in the session.
         */
        void redo();

        /**
         * @brief Destructor. Frees memory associated with images and commands.
         */
        ~Session();
    public:
        std::vector<Image*> images;
        std::vector<Command*> history;
        std::vector<Command*> redos;
        static int current_id;
        bool has_unsaved_changes;
    private:
        int id;
};

#endif