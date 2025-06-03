#ifndef PGM_HPP
#define PGM_HPP

#include "Image.hpp"
#include <vector>
#include <cstdint>

class PGM : public Image {
    public:
        PGM() = default;
        PGM(const std::string& filename);
        PGM(const PGM& rhs);
        void grayscale() override;
        void monochrome() override;
        void negative() override;
        void rotate(const std::string& direction) override;
        void flip(const std::string& direction) override;
        Image* paste_into(Image* img_dest, size_t pos_x, size_t pos_y) override;
        void write_file(std::ofstream& ofs) override;
        Image* clone() const override;
        ~PGM() = default;
    private:
        std::vector<std::vector<uint8_t>> pixels;
        uint8_t max_val;
};

#endif