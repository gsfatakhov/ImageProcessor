#include "Grayscale.h"

Grayscale::Grayscale() {
    filter_type_ = FilterType::RGB;
}
Color Grayscale::GetColor(const Color& previous) const {
    float value = previous.GetR() * 0.299 + previous.GetG() * 0.587 + previous.GetB() * 0.114;
    return Color(value, value, value);
}
std::vector<float> Grayscale::GetRules() const {
    return std::vector<float>();
}
float Grayscale::GetThreshold() const {
    return -1;
}
