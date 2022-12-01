<br>
<br>
<br>

<p align="center">
  <img alt="Image example" src="https://user-images.githubusercontent.com/19341857/205165361-1672b6fa-48bd-4c7f-95d9-56211ddef911.png">
</p>

<br>
<br>

# A C++ container for images

***How to Compile and Run***
```bash
# Compile
g++ -o _ *.cpp

# Run
./_
```

<br>

***Core Design***
- [x] Function to read `.pgm` files.
- [x] Function to save as `.pgm` files. Plus, give the user an
option to save as `P2` type (ASCII) files and also as
`P5` type (binary) files. While `P2` is human readable,
`P5` is not, but `P5` has the advantage of using less disk space.
If not type is specified, all images are saved as `P2` by default.
- [x] All bits are stored as a single-dimensional data.
Normally, we'd stick to STL libraries such as vector to do this.
In this exercise, however, I created an Image class using
dynamically allocated array for learning purposes.

```bash
# Project structure
├── main.cpp     # Main driver
├── Image.cpp    # Definitions for the class and helper functions
└── Image.h      # Declarations for the class and helper functions
```

<br>

***What is `.pgm`?***<br>
Source: https://en.wikipedia.org/wiki/Netpbm#File_formats

> Netpbm (formerly Pbmplus) is an open-source package of graphics programs and a programming library. It is used mainly in the Unix world ...
>
> Several graphics formats are used and defined by the Netpbm project. The portable pixmap format (PPM), the portable graymap format (PGM) and the portable bitmap format (PBM) are image file formats designed to be easily exchanged between platforms ...
>
> The "magic number" (Px) at the beginning of a file determines the type, not the file extension ...
> By the end of 1988, Poskanzer had developed the PGM and PPM formats along with their associated tools and added them to Pbmplus. The final release of Pbmplus was December 10, 1991 ...
>
> Each file starts with a two-byte magic number (in ASCII) that identifies the type of file it is (PBM, PGM, and PPM) and its encoding (ASCII/"plain" or binary/"raw"). The magic number is a capital P followed by a single-digit number.
>
> | ***Type*** | ***Magic number*** | ***Extension*** | ***Colors*** |
> | ---------- | ------------------ | --------------- | ------------ |
> | Portable BitMap | `P1` (ASCII, plain) or `P4` (Binary, raw)  | `.pbm` | `0-1` (white & black) |
> | Portable GrayMap | `P2` (ASCII, plain) or `P5` (Binary, raw)  | `.pgm` | `0-255` (gray scale) or `0-65535` (gray scale) or `any vairable number` (black-to-white- range) |
> | Portable PixMap | `P3` (ASCII, plain) or `P6` (Binary, raw)  | `.ppm` | `16 777 216` (0-255 for each RGB channel) or some support for `0-65535` per channel |
>
> The ASCII ("plain") formats allow for human readability and easy transfer to other platforms; the binary ("raw") formats are more efficient in file size but may have native byte-order issues.
>
> In the binary formats, PBM uses 1 bit per pixel, PGM uses 8 or 16 bits per pixel, and PPM uses 24 bits per pixel: 8 for red, 8 for green, 8 for blue. Some readers and writers may support 48 bits per pixel (16 each for R,G,B), but this is still rare ...
>
> Conventionally PGM stores values in linear color space ...
>
> It is not required that pixels are nicely lined up, the format ignores whitespaces and linefeeds in the data section, although it's recommended that no line is longer than 76 characters ...
>
> The P4 binary format of the same image represents each pixel with a single bit, packing 8 pixels per byte, with the first pixel as the most significant bit. Extra bits are added at the end of each row to fill a whole byte ...
>
> ***PGM example***<br>
> The PGM and PPM formats (both ASCII and binary versions) have an additional parameter for the maximum value (numbers of grey between black and white) after the X and Y dimensions and before the actual pixel data. Black is 0 and max value is white. There is a newline character at the end of each line.
> ```
> P2
> # Shows the word "FEEP" (example from Netpbm man page on PGM)
> 24 7
> 15
> 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
> 0  3  3  3  3  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15 15 15 15  0
> 0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0 15  0
> 0  3  3  3  0  0  0  7  7  7  0  0  0 11 11 11  0  0  0 15 15 15 15  0
> 0  3  0  0  0  0  0  7  0  0  0  0  0 11  0  0  0  0  0 15  0  0  0  0
> 0  3  0  0  0  0  0  7  7  7  7  0  0 11 11 11 11  0  0 15  0  0  0  0
> 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
> ```
> <img alt="pgm ascii example example" src="https://user-images.githubusercontent.com/19341857/204419255-f9d0e254-d8d8-4b05-9359-00d7900a2deb.png" width="380px">
>
> ```
> P5
> 24 7
> 15
> 000000000000000000000000000500050005000000000000000500050005000000000000000555550005000000000000000500050005000000000000000500050005000000000000000000000000000000000000
> ```
> <img alt="pgm binary example" src="https://user-images.githubusercontent.com/19341857/204422179-8e29d573-e839-4f25-a842-2706fcf31878.jpg" width="380px">

<br>
<br>
<br>
