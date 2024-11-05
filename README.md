# img2ansi

## Description

C++ ANSI Art rendering library. 

**Demo**: https://mrogalski.eu/ansi-art

Originally, [ANSI Art](https://en.wikipedia.org/wiki/ANSI_art) is limited to
    <a href="https://en.wikipedia.org/wiki/ANSI_escape_code#3-bit_and_4-bit">16 colors</a> and the
    character set used by the original <a href="https://www.youtube.com/watch?v=_mZBa3sqTrI&t=1061s">IBM PC</a>.</p>
**img2ansi** provides extended version of ANSI Art, up to 24 colors and partial Unicode support.
## Screenshots
  <img src="pictures/sample2.webp"><img src="pictures/sample3.webp"><img src="pictures/sample4.webp">
## Installation
The only dependency is `Freetype`. I highly recommend using CMake as the project includes configured `CMakeLists.txt`.
### Mac OS:
`brew install freetype`

### Linux:
`sudo apt install libfreetype-dev`

### Manual installation via Make:
1. Download latest version from [download page](https://freetype.org/download.html);
2. Unzip && `cd`;
3. `./configure && make`.

## Usage

This library allows you to render any bitmap as an ANSI+ (Extended) Art.

`./run.sh` for demo result.

`<compiled_main.cc> <input_image> <5 ≤ width ≤ 100>` to render any of your images.

In case the image extension isn't supported, it will render the latest successfully
rendered image.

<img src="pictures/example-result.webp">

## API

Full API can be found in `maf/ansi_art.hh`:

```c++
#pragma once

#include <string>

namespace maf {

class AnsiArt {
public:
  static AnsiArt *New();
  
  virtual ~AnsiArt(){};
  virtual std::string LoadTTF(const uint8_t *data, size_t size) = 0;
  virtual void LoadImage(int width, int height, const uint8_t *rgba_bytes) = 0;
  virtual void Render() = 0;

  virtual void StartRender(int n_threads) = 0;
  virtual float GetRenderProgress() = 0;
  virtual void CancelRender() = 0;

  int width = 80;
  std::string forbidden_characters = "";

  std::string glyphs_utf8;       // populated by LoadTTF
  std::string result_c;          // populated by Render
  std::string result_bash;       // populated by Render
  std::string result_raw;        // populated by Render
  int result_rgba_width;         // populated by Render
  int result_rgba_height;        // populated by Render
  std::string result_rgba_bytes; // populated by Render
};

} // namespace maf

```

## Contributions
Feel free to contribute and fork this repository.

The [original repository](https://github.com/mafik/ansi-art) was created by [mafik](https://github.com/mafik), 
forked by [me](https://github.com/illmilo).

## License
This project is under **MIT License**. See [LICENSE](LICENSE) for more.