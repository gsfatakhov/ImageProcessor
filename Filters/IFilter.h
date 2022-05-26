#pragma once
#include <vector>
#include "../Color.h"
enum class FilterType {
    None,
    Resize,
    Matrix,
    RGB,
    Edge,
    Gaus,
    Mirror
};
class IFilter {
public:
    IFilter() = default;
    IFilter(std::vector<float> params);
    FilterType GetType() const;
    virtual std::vector<float> GetRules() const = 0;
    virtual Color GetColor(const Color& previous) const = 0;
    virtual float GetThreshold() const = 0;

protected:
    FilterType filter_type_ = FilterType::None;
    std::vector<float> params_;
};