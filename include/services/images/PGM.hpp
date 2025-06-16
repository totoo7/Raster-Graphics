#ifndef PGM_HPP
#define PGM_HPP

#include "ImageBase.hpp"
#include <cstdint>

class PGM : public ImageBase<uint8_t> {
    public:
        PGM() = default;
        PGM(const std::string& filename);
        PGM(const PGM& rhs);
        void grayscale() override;
        void monochrome() override;
        void negative() override;
        void write_pixel(std::ofstream& ofs, size_t i, size_t j) const override;
        Image* paste_into(Image* img_dest, size_t pos_x, size_t pos_y) override;
        void write_file(std::ofstream& ofs)const override;
        Image* clone() const override;
        uint8_t read_value(std::ifstream& is) const override;
        ~PGM() = default;
    private:
        uint8_t max_val;
};

#endif