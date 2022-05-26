#pragma once
class Color {
public:
    Color() = default;
    Color(float inp_r, float inp_g, float inp_b);
    float NormalizeValue(const float& value);
    Color& operator=(const Color& other);
    float GetR() const;
    float GetG() const;
    float GetB() const;

private:
    float r_ = 0;
    float g_ = 0;
    float b_ = 0;
};