#ifndef SESSION_HPP
#define SESSION_HPP

#include <vector>

class Session {
    public:
        Session();
        const int get_id() const;
        // void add_image(Image* image);
        ~Session() = default;
    public:
        static int current_id;
    private:
        int id;
        // std::vector<Image*> images;
};

#endif