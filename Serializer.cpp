#include "Serializer.h"

Image Serializer::ReadBmp(std::string input_file_name) {
    std::ifstream input;
    input.open(input_file_name, std::ios::in | std::ios::binary);
    if (!input.is_open()) {
        std::cerr << "Не удалось прочитать файл" << std::endl;
        exit(1);
    }
    const int file_header_size = 14;
    const int information_header_size = 40;

    unsigned char file_header[file_header_size];
    input.read(reinterpret_cast<char*>(file_header), file_header_size);

    if (file_header[0] != 'B' || file_header[1] != 'M') {
        std::cerr << "Некорректный формат файла (не BMP)" << std::endl;
        input.close();
        exit(1);
    }

    unsigned char information_header[information_header_size];
    input.read(reinterpret_cast<char*>(information_header), information_header_size);

    if (information_header[14] != 24 || information_header[0] != 40) {
        std::cerr << "Некорректный BMP" << std::endl;
        input.close();
        exit(1);
    }

    unsigned int width = information_header[4] + (information_header[5] << 8) + (information_header[6] << 16) +
                         (information_header[7] << 24);
    unsigned int height = information_header[8] + (information_header[9] << 8) + (information_header[10] << 16) +
                          (information_header[11] << 24);

    Image out_image(width, height);
    const int padding_amount = ((4 - (width * 3) % 4) % 4);
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            unsigned char color[3];
            input.read(reinterpret_cast<char*>(color), 3);
            Color temp_color(static_cast<float>(color[2]) / 255.0f, static_cast<float>(color[1]) / 255.0f,
                             static_cast<float>(color[0]) / 255.0f);
            out_image.SetColor(temp_color, x, y);
        }
        input.ignore(padding_amount);
    }
    input.close();
    // std::cout << "Файл успешно прочитан" << std::endl;
    return out_image;
}
void Serializer::WriteBmp(const Image& image, std::string output_file_name) {
    std::ofstream output;
    output.open(output_file_name, std::ios::out | std::ios::binary);
    if (!output.is_open()) {
        std::cerr << "Не удалось создать файл" << std::endl;
        exit(1);
    }
    unsigned int width = image.GetWidth();
    unsigned int height = image.GetHeight();
    unsigned char bmp_pad[3] = {0, 0, 0};
    const int padding_amount = ((4 - (width * 3) % 4) % 4);
    const int file_header_size = 14;
    const int information_header_size = 40;
    const int file_size = file_header_size + information_header_size + width * height * 3 + padding_amount * height;
    unsigned char file_header[file_header_size];

    file_header[0] = 'B';
    file_header[1] = 'M';

    file_header[2] = file_size;
    file_header[3] = file_size >> 8;
    file_header[4] = file_size >> 16;
    file_header[5] = file_size >> 24;

    for (unsigned int i = 6; i < 14; ++i) {
        file_header[i] = 0;
    }
    file_header[10] = file_header_size + information_header_size;

    unsigned char information_header[information_header_size];
    information_header[0] = information_header_size;
    for (unsigned int i = 1; i < 4; ++i) {
        information_header[i] = 0;
    }
    information_header[4] = width;
    information_header[5] = width >> 8;
    information_header[6] = width >> 16;
    information_header[7] = width >> 24;

    information_header[8] = height;
    information_header[9] = height >> 8;
    information_header[10] = height >> 16;
    information_header[11] = height >> 24;

    information_header[12] = 1;
    information_header[13] = 0;

    information_header[14] = 24;
    for (unsigned int i = 15; i < 40; ++i) {
        information_header[i] = 0;
    }
    output.write(reinterpret_cast<char*>(file_header), file_header_size);
    output.write(reinterpret_cast<char*>(information_header), information_header_size);

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            unsigned char r = static_cast<unsigned char>(image.GetColor(x, y).GetR() * 255.0f);
            unsigned char g = static_cast<unsigned char>(image.GetColor(x, y).GetG() * 255.0f);
            unsigned char b = static_cast<unsigned char>(image.GetColor(x, y).GetB() * 255.0f);

            unsigned char color[] = {b, g, r};
            output.write(reinterpret_cast<char*>(color), 3);
        }
        output.write(reinterpret_cast<char*>(bmp_pad), padding_amount);
    }
    output.close();
    // std::cout << "Файл успешно создан" << std::endl;
}
