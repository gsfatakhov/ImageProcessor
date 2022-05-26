#include "Negative.h"

Negative::Negative() {
    filter_type_ = FilterType::RGB;
}
Color Negative::GetColor(const Color& previous) const {
    return Color(1 - previous.GetR(), 1 - previous.GetG(), 1 - previous.GetB());
}
std::vector<float> Negative::GetRules() const {
    return std::vector<float>();
}
float Negative::GetThreshold() const {
    return -1;
}
