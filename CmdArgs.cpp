#include "CmdArgs.h"

CmdArgs::CmdArgs(int argc, char** argv) {
    if (argc == 1) {
        Help();
        exit(0);
    }
    is_empty_ = false;
    if (argc <= 2) {
        std::cerr << "Введен только 1 параметр";
        exit(1);
    }
    input_file_name_ = std::string(argv[1]);
    output_file_name_ = std::string(argv[2]);
    int ind = 3;
    std::string filter_name;
    while (ind < argc) {
        std::string temp = std::string(argv[ind]);
        if (temp.size() > 1 && temp[0] == '-') {
            filter_name = temp;
            filters_params_[filter_name];
        } else {
            auto param = std::stof(temp);
            if (temp == "v") {
                filters_params_[filter_name].push_back(0.);
            } else if (temp == "h") {
                filters_params_[filter_name].push_back(1.);
            } else if (std::isalpha(temp[0])) {
                filters_params_[filter_name].push_back(-1.);
            } else {
                param = std::stof(temp);
                if (param == 0) {
                    std::cerr << "Некорректный параметр";
                    exit(1);
                }
                filters_params_[filter_name].push_back(param);
            }
        }
        ++ind;
    }
}

void CmdArgs::Help() {
    std::cout << "Эта программа способна применять к фото фильтры\nФормат Ввода:\n{имя программы} {путь к входному "
                 "файлу} {путь к выходному файлу} [-{имя фильтра 1} [параметр фильтра 1] [параметр фильтра 2] ...] "
                 "[-{имя фильтра 2} [параметр фильтра 1] [параметр фильтра 2] ...] ...\nРеализованные фильтры:\nCrop "
                 "(-crop width height)\n Обрезает фото - получаем нужное количество пикселей с левого верхнего "
                 "угла\nGrayscale (-gs)\nПреобразует изображение в оттенки серого\nNegative (-neg)\nПреобразует "
                 "изображение в негатив\nSharpening (-sharp)\nПовышение резкости\nEdge Detection (-edge "
                 "threshold)\nВыделение границ\nGaussian Blur (-blur sigma)\nГауссово размытие\n";
    exit(0);
}
void CmdArgs::MakeChain() {
    FilterFactory factory;
    for (const auto& name : filters_params_) {
        filter_chain_.push_back(factory.GetFilter(name.first, name.second));
    }
}

std::string CmdArgs::GetInput() const {
    return input_file_name_;
}

std::string CmdArgs::GetOutput() const {
    return output_file_name_;
}

const std::vector<IFilter*>& CmdArgs::GetFilterChain() const {
    return filter_chain_;
}
