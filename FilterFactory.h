#pragma once

#include "Filters/IFilter.h"
#include "Filters/Crop.h"
#include "Filters/Grayscale.h"
#include "Filters/Negative.h"
#include "Filters/Sharpening.h"
#include "Filters/EdgeDetection.h"
#include "Filters/GaussianBlur.h"
#include "Filters/Mirror.h"

#include <string>
#include <unordered_map>
#include <iostream>
class FilterFactory {
public:
    FilterFactory();
    static IFilter* GetFilter(const std::string& name, std::vector<float> params);
};