### For handling bytes, we might want to use

std:uint8_t

### Histogram example

```
0: ****
1: **************************
...
255: *****

```

### What is a wedge?

It's the same as a gradient.
The starting point should have the value of 0,
and the end point should have the value of 255.
In this case, the max value happens to be 255 because
all data happen to be stored as 8 bits. 2^8 = 256

### No need to implement smooth.. function

For HW7 Part 2, we don't need to implement this function.
However, we need to implement it if we're doing it as our
final project.

This can be implemented by finding the average of all points
around that particular pixel.

Likewise, constructor for reading a file is not necessary
for HW7 Part 2. It's required only for final project.

<!--

Hw7 Part 2 45 pts								    COSC 226 C++
Chapters 17, 18, 19

Implement a STL-like container for an Image (partial implementation)

Given your design and the mods we made in class today, implement the following:

Implement your image class with
- Handling for unsigned 8-bit images
- Constructors for constant images and wedge images
- Member function to Adjust an image (scale/offset)
- Member function to histogram an image
# Driver code to
- Create a constant image, histogram it, and print the histogram to the screen
- Create a wedge image, histogram it, and print the histogram to the screen

Turn in your code and some sample output in a text file.  Note -- this is NOT a GUI program!


-->
