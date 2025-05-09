#ifndef PGM_HPP
#define PGM_HPP

#include "Image.hpp"
#include <vector>
class PGM : public Image {
    public:
        PGM() = default;
        PGM(const std::string& filename);
        virtual void grayscale() override;
        virtual void monochrome() override;
        virtual void negative() override;
        virtual void rotate(const std::string& direction) override;
        virtual void flip(const std::string& direction) override;
        virtual Image* clone() const override;
        ~PGM() = default;
    private:
        std::vector<std::vector<unsigned int>> pixels;
};

#endif