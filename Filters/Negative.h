#pragma once
#include "IFilter.h"
class Negative : public IFilter {
public:
    Negative();
    Color GetColor(const Color& previous) const override;
    std::vector<float> GetRules() const override;
    float GetThreshold() const override;
};