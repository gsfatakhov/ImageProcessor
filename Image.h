#pragma once
#include "Color.h"
#include <vector>

class Image {
public:
    Image(unsigned int width, unsigned int height);
    Color GetColor(unsigned int x, unsigned int y) const;
    void SetColor(const Color& color, unsigned int x, unsigned int y);
    unsigned int GetWidth() const;
    unsigned int GetHeight() const;

private:
    unsigned int width_ = 0;
    unsigned int height_ = 0;
    std::vector<Color> colors_;
};