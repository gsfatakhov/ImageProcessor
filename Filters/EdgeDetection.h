#pragma once
#include "IFilter.h"
class EdgeDetection : public IFilter {
public:
    EdgeDetection(std::vector<float> params);
    Color GetColor(const Color& previous) const override;
    std::vector<float> GetRules() const override;
    float GetThreshold() const override;;
};