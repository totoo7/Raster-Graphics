#ifndef SESSION_HPP
#define SESSION_HPP

#include <vector>
#include "Image.hpp"
class Session {
    public:
        Session();
        Session(const Session& rhs);
        Session& operator=(const Session& rhs);
        const int get_id() const;
        void add_image(Image* image);
        void rotate(const std::string& direction);
        void flip(const std::string& direction);
        void save();
        void saveAs(const std::vector<std::string>& files);
        ~Session();
    public:
        static int current_id;
        std::vector<Image*> images;
    private:
        int id;
};

#endif