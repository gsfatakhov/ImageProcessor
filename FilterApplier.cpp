#include "FilterApplier.h"
Image FilterApplier::Apply(const IFilter& filter, Image& image) {
    if (filter.GetType() == FilterType::Resize) {
        unsigned int width = std::min(static_cast<unsigned int>(filter.GetRules()[0]), image.GetWidth());
        unsigned int height = std::min(static_cast<unsigned int>(filter.GetRules()[1]), image.GetHeight());
        return Resize(image, width, height);

    } else if (filter.GetType() == FilterType::RGB) {
        return RGB(filter, image);
    } else if (filter.GetType() == FilterType::Matrix) {
        return Matrix(image, filter.GetRules(), filter.GetThreshold());
    } else if (filter.GetType() == FilterType::Edge) {
        Image new_image = RGB(filter, image);
        new_image = Matrix(new_image, filter.GetRules(), filter.GetThreshold());
        return new_image;
    } else if (filter.GetType() == FilterType::Gaus) {
        unsigned int width = image.GetWidth();
        unsigned int height = image.GetHeight();

        Image new_image = Image(width, height);
        float sigma = filter.GetThreshold();

        for (unsigned int y = 0; y < height; ++y) {
            for (unsigned int x = 0; x < width; ++x) {
                float r = 0;
                float g = 0;
                float b = 0;
                for (int y_shift : {-2, -1, 0, 1, 2}) {
                    for (int x_shift : {-2, -1, 0, 1, 2}) {
                        Color temp = image.GetColor(x + x_shift, y + y_shift);
                        r += temp.GetR() / (2 * M_PI * sigma * sigma) *
                             pow(M_E, -(pow(static_cast<int>(x) - static_cast<int>(x_shift), 2) +
                                        pow(static_cast<int>(y) - static_cast<int>(y_shift), 2)) /
                                          (2 * sigma * sigma));
                        g += temp.GetG() / (2 * M_PI * sigma * sigma) *
                             pow(M_E, -(pow(static_cast<int>(x) - static_cast<int>(x_shift), 2) +
                                        pow(static_cast<int>(y) - static_cast<int>(y_shift), 2)) /
                                          (2 * sigma * sigma));
                        b += temp.GetB() / (2 * M_PI * sigma * sigma) *
                             pow(M_E, -(pow(static_cast<int>(x) - static_cast<int>(x_shift), 2) +
                                        pow(static_cast<int>(y) - static_cast<int>(y_shift), 2)) /
                                          (2 * sigma * sigma));
                    }
                }
                new_image.SetColor(Color(r, g, b), x, y);
            }
        }
        return new_image;
    } else if (filter.GetType() == FilterType::Mirror) {
        unsigned int width = image.GetWidth();
        unsigned int height = image.GetHeight();

        Image new_image = Image(width, height);

        float parametr = filter.GetThreshold();
        if (parametr != 0 and parametr != 1) {
            std::cerr << "Неправильный параметр фитьтра отзеркаливания";
            exit(1);
        }

        if (parametr == 1) {
            for (unsigned int y = 0; y < height; ++y) {
                for (unsigned int x = 0; x < width; ++x) {
                    new_image.SetColor(image.GetColor(x, y), width - 1 - x, y);
                }
            }
        } else {
            for (unsigned int y = 0; y < height; ++y) {
                for (unsigned int x = 0; x < width; ++x) {
                    new_image.SetColor(image.GetColor(x, y), x, height - y - 1);
                }
            }
        }
        return new_image;
    }
    std::cerr << "Неправильный тип фильтра";
    exit(1);
}
Image FilterApplier::Resize(Image& image, unsigned int width, unsigned int height) {
    unsigned int shift = image.GetHeight() - height;
    Image new_image = Image(width, height);
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            new_image.SetColor(image.GetColor(x, shift + y), x, y);
        }
    }
    return new_image;
}

Image FilterApplier::RGB(const IFilter& filter, Image& image) {
    unsigned int width = image.GetWidth();
    unsigned int height = image.GetHeight();

    Image new_image = Image(width, height);
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            new_image.SetColor(filter.GetColor(image.GetColor(x, y)), x, y);
        }
    }
    return new_image;
}
Image FilterApplier::Matrix(Image& image, std::vector<float> matrix, float threshold) {
    unsigned int width = image.GetWidth();
    unsigned int height = image.GetHeight();
    Image new_image = Image(width, height);

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            std::vector<Color> temp;
            for (int y_shift : {-1, 0, 1}) {
                for (int x_shift : {-1, 0, 1}) {
                    temp.push_back(image.GetColor(x + x_shift, y + y_shift));
                }
            }

            float r = 0;
            float g = 0;
            float b = 0;
            for (int i = 0; i < 9; ++i) {
                r += matrix[i] * temp[i].GetR();
                g += matrix[i] * temp[i].GetG();
                b += matrix[i] * temp[i].GetB();
            }
            if (threshold == -1) {
                new_image.SetColor(Color(r, g, b), x, y);
            } else if (r > threshold) {
                new_image.SetColor(Color(1, 1, 1), x, y);
            } else {
                new_image.SetColor(Color(0, 0, 0), x, y);
            }
        }
    }
    return new_image;
}
