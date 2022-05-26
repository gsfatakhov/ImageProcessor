#pragma once
#include "Image.h"
#include "Filters/IFilter.h"
#include <iostream>
#include <cmath>

class FilterApplier {
public:
    FilterApplier() = default;
    static Image Apply(const IFilter& filter, Image& image);

private:
    static Image Resize(Image& image, unsigned int width, unsigned int height);
    static Image RGB(const IFilter& filter, Image& image);
    static Image Matrix(Image& image, std::vector<float> matrix, float threshold);
};