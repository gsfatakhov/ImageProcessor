#pragma once
#include "IFilter.h"
class Sharpening : public IFilter {
public:
    Sharpening();
    Color GetColor(const Color& previous) const override;
    std::vector<float> GetRules() const override;
    float GetThreshold() const override;
};