#ifndef PPM_HPP
#define PPM_HPP

#include "ImageBase.hpp"
#include <cstdint>

struct RGB {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

class PPM : public ImageBase<RGB> {
    public:
        PPM() = default;
        PPM(const std::string& filename);
        PPM(const PPM& rhs);
        void grayscale() override;
        void monochrome() override;
        void negative() override;
        void write_pixel(std::ofstream& ofs, size_t i, size_t j) const override;
        Image* paste_into(Image* img_dest, size_t pos_x, size_t pos_y) override;
        void write_file(std::ofstream& ofs)const override;
        Image* clone() const override;
        RGB read_value(std::ifstream& is) const override;
        ~PPM() = default;
    private:
        uint8_t max_val;
};

#endif