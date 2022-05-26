#include "Mirror.h"

Mirror::Mirror(std::vector<float> params) : IFilter(params) {
    filter_type_ = FilterType::Mirror;
}
Color Mirror::GetColor(const Color& previous) const {
    return Color();
}
std::vector<float> Mirror::GetRules() const {
    return std::vector<float>();
}
float Mirror::GetThreshold() const {
    try {
        return params_[0];
    } catch (...) {
        std::cerr << "Отсутсвует параметр";
        exit(1);
    }
}
