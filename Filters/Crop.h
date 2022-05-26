#pragma once
#include "IFilter.h"
class Crop : public IFilter {
public:
    Crop(std::vector<float> params);
    std::vector<float> GetRules() const override;
    Color GetColor(const Color& previous) const override;
    float GetThreshold() const override;
};