#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <ios>
#include "Image.h"
#include "Color.h"
class Serializer {
public:
    static Image ReadBmp(std::string input_file_name);
    static void WriteBmp(const Image& image, std::string output_file_name);
};
