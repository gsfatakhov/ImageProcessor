#include "Sharpening.h"

Sharpening::Sharpening() {
    filter_type_ = FilterType::Matrix;
}
Color Sharpening::GetColor(const Color& previous) const {
    return Color();
}
std::vector<float> Sharpening::GetRules() const {
    return {0, -1, 0, -1, 5, -1, 0, -1, 0};
}
float Sharpening::GetThreshold() const {
    return -1;
}
