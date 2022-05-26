#include "Crop.h"
std::vector<float> Crop::GetRules() const {
    return params_;
}
Crop::Crop(std::vector<float> params) {
    filter_type_ = FilterType::Resize;
    params_ = params;
}
Color Crop::GetColor(const Color& previous) const {
    return Color();
}
float Crop::GetThreshold() const {
    return -1;
}
