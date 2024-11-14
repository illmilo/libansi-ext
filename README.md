# libansi-ext

## Description

C++ ANSI Art rendering library. 

**Demo**: https://mrogalski.eu/ansi-art

Originally, [ANSI Art](https://en.wikipedia.org/wiki/ANSI_art) is limited to
    <a href="https://en.wikipedia.org/wiki/ANSI_escape_code#3-bit_and_4-bit">16 colors</a> and the
    character set used by the original <a href="https://www.youtube.com/watch?v=_mZBa3sqTrI&t=1061s">IBM PC</a>.</p>
**libansi-ext** provides extended version of ANSI Art, up to 24 colors and partial Unicode support.
## Screenshots
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

This library allows you to render any bitmap media as an ANSI+ (Extended) Art.

```bash
<compiled_main.cc> <video/image> <path\to\file>`
```
## API

Full API can be found in `src/ansi_art.hh`:

## Contributions
Feel free to contribute and fork this repository.

The [original repository](https://github.com/mafik/ansi-art) was created by [mafik](https://github.com/mafik), 
forked by [me](https://github.com/illmilo).

## License
This project is under **MIT License**. See [LICENSE](LICENSE) for more.