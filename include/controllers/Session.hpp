#ifndef SESSION_HPP
#define SESSION_HPP

#include <vector>
#include "Image.hpp"
class Session {
    public:
        Session();
        const int get_id() const;
        void add_image(Image* image);
        void save();
        ~Session() = default;
    public:
        static int current_id;
        std::vector<Image*> images;
    private:
        int id;
};

#endif