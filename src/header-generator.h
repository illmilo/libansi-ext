//
// Created by illmilo on 05/11/2024.
//
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <string>
#include <fstream>

using namespace std;

#ifndef IMG2ANSI_HEADER_GENERATOR_H
#define IMG2ANSI_HEADER_GENERATOR_H

#endif //IMG2ANSI_HEADER_GENERATOR_H

// takes in *.img -> creates *.h with struct of that image to be processed
void generateImg(const string& inputImg, const string& outputH) {
    int width, height, channels;
    // force RGBA
    unsigned char* imgData = stbi_load(inputImg.c_str(), &width, &height, &channels, 4);

    if (!imgData) {
        printf("Error: Couldn't load image %s\n", inputImg.c_str());
        return;
    }

    ofstream outFile(outputH);
    if (!outFile.is_open()) {
        printf("Error: Couldn't open file %s\n", outputH.c_str());
        stbi_image_free(imgData);
        return;
    }

    // header structure
    outFile << "#pragma once\n\n"
               "static const struct {\n"
               "    unsigned int width, height;\n"
               "    unsigned char pixel_data[" << (width * height * 4 + 1) << "];\n"
                                                                              "} example_image = {\n"
                                                                              " " << width << ", " << height << ",\n"
                                                                                                                "   \"";
    // generating pixel data
    for (int i = 0; i < width * height * 4; i++) {
        outFile << "\\x" << hex << (int)imgData[i];
        if ((i + 1) % (width * 4) == 0) outFile << "\"\n"
                                                   "    \"";
    }
    outFile << "\"\n"
               "};\n";

    outFile.close();

    stbi_image_free(imgData);

    printf("Header file %s generated successfully.\n", outputH.c_str());
}