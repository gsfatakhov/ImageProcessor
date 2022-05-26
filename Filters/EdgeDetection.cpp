#include "EdgeDetection.h"
#include <iostream>
EdgeDetection::EdgeDetection(std::vector<float> params) : IFilter(params) {
    filter_type_ = FilterType::Edge;
    params_ = params;
}

Color EdgeDetection::GetColor(const Color& previous) const {
    float value = previous.GetR() * 0.299 + previous.GetG() * 0.587 + previous.GetB() * 0.114;
    return Color(value, value, value);
}
std::vector<float> EdgeDetection::GetRules() const {
    return {0, -1, 0, -1, 4, -1, 0, -1, 0};
}

float EdgeDetection::GetThreshold() const {
    try {
        if (params_[0] < 0) {
            return 0;
        }
        return params_[0] / 255.0f;
    } catch (...) {
        std::cerr << "Отсутсвуте параметр";
        exit(1);
    }
}
