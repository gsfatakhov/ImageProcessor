#include "GaussianBlur.h"

GaussianBlur::GaussianBlur(std::vector<float> params) : IFilter(params) {
    filter_type_ = FilterType::Gaus;
    params_ = params;
}

Color GaussianBlur::GetColor(const Color& previous) const {
    return Color();
}
std::vector<float> GaussianBlur::GetRules() const {
    return {};
}
float GaussianBlur::GetThreshold() const {
    try {
        if (params_[0] < 0) {
            return 0;
        }
        return params_[0];
    } catch (...) {
        std::cerr << "Отсутсвуте параметр";
        exit(1);
    }
}