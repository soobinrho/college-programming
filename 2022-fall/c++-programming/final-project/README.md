<br>
<br>
<br>

<p align="center">
  <img alt="Image example" src="https://user-images.githubusercontent.com/19341857/206621901-49d342fb-2854-4796-ad12-4fc58b8b55e8.png">
</p>

<br>
<br>

# C++ container for images
An STL-like container that can read and write images in either binary or
ASCII adhering to the PGM specifications outlined by the
[Netpbm](https://netpbm.sourceforge.net/doc/pgm.html)
open-source graphics library. Tested for memory leaks using
[Valgrind Memcheck](https://valgrind.org/docs/manual/mc-manual.html).

<br>

***How to Compile and Run***
```bash
# Compile
g++ -o _ *.cpp

# Run
./_
```

<br>

***Functions Examples***
```c++
#include "Image.h"

int main() {

  // ----------------------------------------------------------------
  // 0. Construct an image.
  // ----------------------------------------------------------------
  RhoPGM::Image imageEg{};

  // ----------------------------------------------------------------
  // 1. Save the image as a P2 type `.pgm` (ASCII) file and
  //    also as a P5 type `.pgm` (binary) file.
  // ----------------------------------------------------------------
  RhoPGM::pgmSaveAsFile(imageEg,"imageExample.pgm");
  RhoPGM::pgmSaveAsFile(imageEg,"imageExampleBinary.pgm","P5");

  // ----------------------------------------------------------------
  // 2. Read from a P2 type `.pgm` (ASCII) file and
  //    also as a P5 type `.pgm` (binary) file.
  // ----------------------------------------------------------------
  RhoPGM::Image imageFromP2{"imageExample.pgm"};
  RhoPGM::Image imageFromP5{"imageExampleBinary.pgm"};

  // ----------------------------------------------------------------
  // 3. Print a histogram of the image.
  // ----------------------------------------------------------------
  RhoPGM::pgmPrintHistogram(imageEg);

  // ----------------------------------------------------------------
  // 4. A funciton for adjusting the brightness of an image.
  // ----------------------------------------------------------------
  imageFromP2.setBrightness(0.99,-4);
  RhoPGM::pgmSaveAsFile(imageFromP2,"imageExampleBrightness.pgm");

  // ----------------------------------------------------------------
  // 5. A function for getting a subset of an image.
  // ----------------------------------------------------------------
  RhoPGM::Image imageEgSubset = imageEg.getSubset(0,0,1000,1000);
  RhoPGM::pgmSaveAsFile(imageEgSubset,"imageExampleSubset.pgm");

  // ----------------------------------------------------------------
  // 6. A function for downsampling an image
  // ----------------------------------------------------------------
  RhoPGM::Image imageEgDownsample = imageEg.getDownsample();
  RhoPGM::pgmSaveAsFile(imageEgDownsample,"imageExampleDownsample.pgm");

  // Return 0 to signal success
  return 0;
}
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

***How to check for memory leaks using Valgrind Memcheck***<br>
```bash
# Source:
#   https://valgrind.org/docs/manual/quick-start.html
valgrind --leak-check=yes ./_
```

According to the test results, this container does not
have any memory leak.
```
==83136== Memcheck, a memory error detector
==83136== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==83136== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==83136== Command: ./_
==83136== 
 0:*
 1:*
 2:**
 3:***
 4:****
 5:*****
 6:******
 7:*******
 8:********
 9:********
10:*********
11:**********
12:***********
13:************
14:*************
15:*
==83136== 
==83136== HEAP SUMMARY:
==83136==     in use at exit: 0 bytes in 0 blocks
==83136==   total heap usage: 36 allocs, 36 frees, 27,760,198 bytes allocated
==83136== 
==83136== All heap blocks were freed -- no leaks are possible
==83136== 
==83136== For lists of detected and suppressed errors, rerun with: -s
==83136== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

<br>
<br>
<br>
