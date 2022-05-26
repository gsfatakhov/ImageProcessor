#pragma once
#include "IFilter.h"
#include <iostream>

class GaussianBlur : public IFilter {
public:
    GaussianBlur() = default;
    GaussianBlur(std::vector<float> params);
    Color GetColor(const Color& previous) const override;
    std::vector<float> GetRules() const override;
    float GetThreshold() const override;
};
