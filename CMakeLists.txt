cmake_minimum_required(VERSION 3.17)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)

add_executable(image_processor
        CmdArgs.cpp
        image_processor.cpp
        CmdArgs.h
        Serializer.cpp
        Serializer.h
        Image.cpp
        Image.h
        FilterFactory.cpp
        FilterFactory.h
        Filters/IFilter.cpp
        Filters/IFilter.h
        Color.cpp Color.h
        Filters/Crop.cpp
        Filters/Crop.h
        FilterApplier.cpp
        FilterApplier.h
        Filters/Grayscale.cpp
        Filters/Grayscale.h
        Filters/Negative.cpp
        Filters/Negative.h
        Filters/Sharpening.cpp
        Filters/Sharpening.h
        Filters/EdgeDetection.cpp
        Filters/EdgeDetection.h
        Filters/GaussianBlur.cpp
        Filters/GaussianBlur.h Filters/Mirror.cpp Filters/Mirror.h)
