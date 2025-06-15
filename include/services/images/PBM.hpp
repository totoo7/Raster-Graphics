#ifndef PBM_HPP
#define PBM_HPP

#include "ImageBase.hpp"

class PBM : public ImageBase<bool> {
    public:
        PBM() = default;
        PBM(const std::string& filename);
        PBM(const PBM& rhs);
        void grayscale() override;
        void monochrome() override;
        void negative() override;
        Image* paste_into(Image* img_dest, size_t pos_x, size_t pos_y) override;
        void write_file(std::ofstream& ofs) override;
        Image* clone() const override;
};

#endif