#pragma once
#include "IFilter.h"

class Grayscale : public IFilter {
public:
    Grayscale();
    Color GetColor(const Color& previous) const override;
    std::vector<float> GetRules() const override;
    float GetThreshold() const override;
};