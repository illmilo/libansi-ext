#include "src/ansi_art.hh"
#include "src/image.h"
#include "src/font.h"

#include "src/header-generator.h"

int main(int argc, char* argv[]) {
    int width = stoi(argv[2]);
    if (argc != 3 || width > 100 || width < 5) {
        printf("Usage: %s <input_image> <5 ≤ width ≤ 100>\n", argv[0]);
        return 1;
    }
    generateImg(argv[1], "src/image.h");

  printf("Rendering... (this may take a few seconds)\n");
  auto art = maf::AnsiArt::New();
  art->LoadImage(example_image.width, example_image.height, example_image.pixel_data);
  art->LoadTTF(UbuntuMono_R_ttf, UbuntuMono_R_ttf_len);
  art->width = width;
  art->Render();
  printf("%s", art->result_raw.c_str());
  delete art;
  return 0;
}
