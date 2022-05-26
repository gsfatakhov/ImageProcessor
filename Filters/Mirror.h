#pragma once
#include "IFilter.h"
#include "iostream"

class Mirror : public IFilter {
public:
    Mirror() = default;
    Mirror(std::vector<float> params);
    Color GetColor(const Color& previous) const override;
    std::vector<float> GetRules() const override;
    float GetThreshold() const override;
};
