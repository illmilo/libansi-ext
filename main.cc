#include "src/ansi_art.hh"
#include "res/image.h"
#include "res/font.h"

#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "res/header-generator.h"

int processVideo(char* file) {
    auto video = cv::VideoCapture(file);
    if (video.isOpened()) {
        video.set(cv::CAP_PROP_POS_FRAMES, 10);

        cv::Mat frame;
        bool done = video.read(frame);
        if (done) {
            cv::imshow("frame", frame);cv::waitKey(0);
            if (cv::imwrite("frame.png", frame)) {
                cout << "Frame saved as frame.png to " << std::filesystem::current_path() << std::endl;
            } else {
                printf("Failed to save frame.\n");
            }
        }
        return 0;
    }

    return 1;   // not supported format
}

int processImage(char* image) {
    generateImg(image, "res/image.h");

    printf("Rendering...\n");
    auto art = maf::AnsiArt::New();
    art->LoadImage(example_image.width, example_image.height, example_image.pixel_data);
    art->LoadTTF(UbuntuMono_R_ttf, UbuntuMono_R_ttf_len);
    art->width = 20;
    art->Render();
    printf("%s", art->result_raw.c_str());
    delete art;
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <video/image> <file>\n", argv[0]);
        return 1;
    }

    if (strcmp("video", argv[1])==0) processVideo(argv[2]);
    else if (strcmp("image", argv[1])==0) processImage(argv[2]);
    else {
        printf("Invalid mode selected. Please, type `video` or `image`.");
        return 1;
    }
  return 0;
}
