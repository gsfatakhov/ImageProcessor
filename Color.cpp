#include "Color.h"
Color::Color(float inp_r, float inp_g, float inp_b)
    : r_(NormalizeValue(inp_r)), g_(NormalizeValue(inp_g)), b_(NormalizeValue(inp_b)) {
}
Color& Color::operator=(const Color& other) {
    r_ = other.GetR();
    g_ = other.GetG();
    b_ = other.GetB();
    return *this;
}
float Color::NormalizeValue(const float& value) {
    if (value <= 0) {
        return 0;
    } else if (value >= 1) {
        return 1;
    }
    return value;
}
float Color::GetR() const {
    return r_;
}
float Color::GetG() const {
    return g_;
}
float Color::GetB() const {
    return b_;
}
