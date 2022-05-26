#include "FilterFactory.h"
FilterFactory::FilterFactory() {
}
IFilter* FilterFactory::GetFilter(const std::string& name, std::vector<float> params) {
    if (name == "-crop") {
        return new Crop(params);
    } else if (name == "-gs") {
        return new Grayscale();
    } else if (name == "-neg") {
        return new Negative();
    } else if (name == "-sharp") {
        return new Sharpening();
    } else if (name == "-edge") {
        return new EdgeDetection(params);
    } else if (name == "-blur") {
        return new GaussianBlur(params);
    }
    else if (name == "-mirror") {
        return new Mirror(params);
    }

    std::cerr << "Фильтр не найден" << std::endl;
    exit(1);
}
