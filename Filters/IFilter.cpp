#include "IFilter.h"

IFilter::IFilter(std::vector<float> params) : params_(params) {
}
FilterType IFilter::GetType() const {
    return filter_type_;
}
