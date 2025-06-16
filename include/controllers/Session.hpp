#ifndef SESSION_HPP
#define SESSION_HPP

#include <vector>
#include "Image.hpp"
#include "Command.hpp"

class Session {
    public:
        Session();
        Session(const Session& rhs);
        Session& operator=(const Session& rhs);
        const int get_id() const;
        void add_image(Image* image);
        void rotate(const std::string& direction);
        void flip(const std::string& direction);
        void monochrome();
        void negative();
        void grayscale();
        void save();
        void saveAs(const std::vector<std::string>& files);
        void undo();
        void redo();
        ~Session();
    public:
        std::vector<Image*> images;
        std::vector<Command*> history;
        std::vector<Command*> redos;
        static int current_id;
    private:
        int id;
};

#endif