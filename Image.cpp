#include "Image.h"
Image::Image(unsigned int width, unsigned int height)
    : width_(width), height_(height), colors_(std::vector<Color>(width * height)) {
}

Color Image::GetColor(unsigned int x, unsigned int y) const {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        return Color();
    }
    return colors_[y * width_ + x];
}
void Image::SetColor(const Color& color, unsigned int x, unsigned int y) {
    colors_[y * width_ + x] = color;
}

unsigned int Image::GetWidth() const {
    return width_;
}

unsigned int Image::GetHeight() const {
    return height_;
}
