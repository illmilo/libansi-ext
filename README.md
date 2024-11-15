# libansi-ext

## Description

C++ ANSI-Extended Art rendering library. 

**Demo**: https://mrogalski.eu/ansi-art

__Why extended?__
Originally, [ANSI Art](https://en.wikipedia.org/wiki/ANSI_art) is limited to
    <a href="https://en.wikipedia.org/wiki/ANSI_escape_code#3-bit_and_4-bit">16 colors</a> and the
    character set used by the original <a href="https://www.youtube.com/watch?v=_mZBa3sqTrI&t=1061s">IBM PC</a>.</p>
**libansi-ext** provides extended version of ANSI Art, up to 24 colors and Unicode support.
## Sample
  <img src="pictures/sample2.webp"><img src="pictures/sample3.webp"><img src="pictures/sample4.webp">
## Installation

It is highly recommended to use CMake for this project build.
Dependencies:
- `Freetype`
- `OpenCV`
### Mac OS:
```bash
brew install freetype opencv
```

### Linux:
```bash
sudo apt install libfreetype-dev libopencv-dev
```

### Windows:
Manual installation from official websites of `Freetype` and `OpenCV`.

## Usage
```bash
<compiled_main.cc> <video/image> <path\to\file>`
```
## API
Full API can be found in `src/ansi_art.hh`:

## Contributions
Feel free to contribute and fork this repository.

I cloned this repo from [mafik](https://github.com/mafik/ansi-art) and added a lot of functionalities for it to be independent project.

## License
This project is under **MIT License**. See [LICENSE](LICENSE) for more.