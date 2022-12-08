/*
 *    Soobin Rho
 *    Fall, 2022
 *    COSC 226: C++ Programming
 *
 *    Final Project: STL-like Image Container
 *
 *    While the header file contains all the declarations,
 *    this file has all their definitions.
 */

#include "Image.h"

// --------------------------------------------------------------------
// Class operator overloading
// --------------------------------------------------------------------
Image &Image::operator=(Image &&image) {
  pgmType = image.pgmType;
  totalColumn = image.totalColumn;
  totalRow = image.totalRow;
  maxValue = image.maxValue;

  // Move the pointer to the new values and delete the old values
  delete[] values;
  values = image.values;
  return *this;
}

bool operator==(const Image &image1, const Image &image2) {
  // Check the magic number and the image dimension
  if (image1.pgmType != image2.pgmType ||
      image1.totalColumn != image2.totalColumn ||
      image1.totalRow != image2.totalRow ||
      image1.maxValue != image2.maxValue) {
    return false;
  }

  // Compare all values
  else {
    for (int i = 0; i < image1.size(); ++i) {
      if (image1[i] != image2[i])
        return false;
    }
  }

  return true;
}

bool operator!=(const Image &image1, const Image &image2) {
  return !(image1 == image2);
}

std::ostream &operator<<(std::ostream &ost, const Image &image) {
  /*
   *  OUTPUT STREAM OPERATOR OVERLOADING
   *
   *  Two possibilities:
   *  1. pgmType is P2. In this case, print all values in ASCII.
   *  2. pgmType is P5. In this case, print all values as bytes.
   */

  // Output the magic number, image dimension, and maximum value
  ost << image.pgmType << '\n'
      << image.totalColumn << ' ' << image.totalRow << '\n'
      << image.maxValue << '\n';

  // Output all color values in ASCII
  if (image.pgmType == "P2") {
    for (int i = 0; i < image.size(); ++i) {
      if (i % image.totalColumn == 0 && i != 0)
        ost << '\n';
      ost << image.values[i] << ' ';
    }
  }

  // Output all color values as bytes
  else if (image.pgmType == "P5") {
    for (int i = 0; i < image.size(); ++i) {
      ost << char(image.values[i]);
    }
  }

  // Add a whitespace at the end for better readability
  ost << '\n';

  return ost;
}

std::istream &operator>>(std::istream &ist, Image &image) {
  /*
   *  INPUT STREAM OPERATOR OVERLOADING
   *
   *  Two possibilities:
   *  1. pgmType is P2. In this case, read color values in ASCII.
   *  2. pgmType is P5. In this case, read color values as bytes.
   *
   */

  // First of all, parse pgmType, image dimensions
  // (column * row), and the maximum color value.
  // Ignore any line starting with `#`.
  const int NUM_OF_CONFIGS{4};
  int numOfConfigsFound{0};
  bool isFound{false};

  std::string linesBuffer;
  std::stringstream lineContainingAllConfigs;
  while (!isFound && std::getline(ist, linesBuffer)) {
    if (linesBuffer[0] != '#') {

      // Break the line into words so that we can count
      // how many configs we've parsed
      std::stringstream lineBuffer{linesBuffer};
      std::string wordBuffer;
      while (lineBuffer >> wordBuffer) {
        ++numOfConfigsFound;
        lineContainingAllConfigs << wordBuffer << ' ';

        // Exit the loop when we found all configs
        if (numOfConfigsFound >= NUM_OF_CONFIGS) {
          isFound = true;
          break;
        }
      }
    }
  }

  // Assign the config values
  lineContainingAllConfigs >> image.pgmType >> image.totalColumn >>
      image.totalRow >> image.maxValue;

  // Reset the current color values
  if (image.values != nullptr)
    delete[] image.values;
  image.values = new int[image.size()];

  // ---------------------------------------------------------------
  // 1. If pgmType is "P2", parse color values as string
  // ---------------------------------------------------------------
  if (image.pgmType == "P2") {
    for (int i = 0; i < image.size(); ++i) {
      ist >> image.values[i];
    }
  }

  // ---------------------------------------------------------------
  // 2. If pgmType is "P5", parse color values as bytes
  // ---------------------------------------------------------------
  else if (image.pgmType == "P5") {
    int8_t value;
    void *valueAddress = &value;
    for (int i = 0; i < image.size(); ++i) {
      ist.read(static_cast<char *>(valueAddress), sizeof(char));
      image.values[i] = value;
    }
  }

  else
    throw std::runtime_error("[ERROR] pgmType should be either P2 or P5.");

  return ist;
}

// --------------------------------------------------------------------
// Constructor by an existing file definition
// --------------------------------------------------------------------
Image::Image(std::string fileName) {
  // Open the file
  std::ifstream file{fileName, std::ios_base::binary};
  if (!file) {
    throw std::runtime_error("[ERROR] Can't open the file.");
    return;
  }

  // ----------------------------------------------------------------
  // >> operator below will execute `delete[] values` to prevent
  // memory leak. This, however, can lead to an error if it tries
  // to do that even when `this<-values` does not exist.
  //
  // Therefore, I set `this<-values` as nullptr here so that the
  // operator overloading can know that its values don't exist.
  // Otherwise, `this<-values` points to a random memory and might
  // cause the operator overloading to delete a random memory.
  // ----------------------------------------------------------------
  values = nullptr;

  // Read the color values from the file
  file >> *this;
}

// --------------------------------------------------------------------
// Class member functions definitions
// --------------------------------------------------------------------
std::vector<int> Image::getHistogram() const {
  // Count occurences of each color value. Initialize a vector with
  // `maxValue+1` elements set to 0.
  std::vector<int> counts(maxValue + 1, 0);
  for (int i = 0; i < size(); ++i)
    ++counts[values[i]];

  return counts;
}

void Image::setBrightness(double scale, int offset) {
  /*
   *  A function for setting the brightness of the image
   */
  for (int i = 0; i < size(); ++i) {
    // Apply scale and offset
    values[i] = static_cast<int>(values[i] * scale + offset);

    // Range check
    if (values[i] > maxValue)
      values[i] = maxValue;
    else if (values[i] < 0)
      values[i] = 0;
  }
}

Image Image::getSubset(int x, int y, int xLength, int yLength) {
  // Range check
  if (xLength + x > totalColumn || yLength + y > totalRow) {
    throw std::runtime_error("[ERROR] Invalid subset size.");
  }

  // In order to get the subset, we create a new Image instance.
  // `unique_ptr` is used so that it can be returned to the function
  // call at the end of this function and not get destroyed
  // outside this function scope.
  std::unique_ptr<Image> subset(
      new Image{pgmType, xLength, yLength, maxValue, 0});

  // Translate the `x` and `y` values into an index value
  int startIndex = (y * totalColumn) + x;

  // Get the subset
  int subsetIndex = 0;
  for (int yIndex = 0; yIndex < yLength; ++yIndex) {
    for (int xIndex = 0; xIndex < xLength; ++xIndex) {
      int originalIndex = startIndex + (yIndex * totalColumn) + xIndex;
      subset->values[subsetIndex] = values[originalIndex];
      ++subsetIndex;
    }
  }

  return *subset;
}

// A member function to downsample an image by 2 in the line direction
// and by 2 in the sample direction. Include an option to smooth here.
// It will return a new image. (to smooth an image, average a pixel's
// neighbors.
std::unique_ptr<Image> Image::getDownsample(int neightborPixels) {
  std::unique_ptr<Image> temp(new Image{13});
  return temp;
}

// --------------------------------------------------------------------
// Helper functions definitions
// --------------------------------------------------------------------
void pgmPrintHistogram(const Image &image) {
  std::vector<int> counts = image.getHistogram();

  // Print the results. Align all values neatly.
  // Find how many widths are required for alignment.
  const int howManyTens = std::floor(std::log10(image.maxValue)) + 1;
  for (int i = 0; i < image.maxValue + 1; ++i) {
    std::cout << std::setw(howManyTens) << i << ':';

    // Calculate percentage and print '*' the same amount
    double percentage = static_cast<double>(counts[i]) / image.size() * 100;
    percentage = std::round(percentage);

    // Range check. It's possible for a value to be below 1%, but
    // impossible for it to be above 100%, so only check for 1%.
    if (percentage < 1)
      percentage = 1;

    // Print `*` percentage times. There should be 100 stars
    // ideally, but there could be more than or less than
    // 100 because of rounding.
    for (int count = 0; count < percentage; ++count) {
      std::cout << '*';
    }

    // End of histogram
    std::cout << '\n';
  }
}

void pgmSaveAsFile(const Image &image, std::string fileName) {
  std::ofstream ofs{fileName};
  if (!ofs)
    throw std::runtime_error("[ERROR] Failed to initiate an output stream.");
  else
    ofs << image;
}

void pgmSaveAsFile(Image &image, std::string fileName, std::string pgmType) {
  /*
   * TWO POSSIBILITES
   * 1. If the pgmType in the funciton call is not the same as
   *    the pgmType that the image already has.
   *    In this case, change the pgmType to that one temporarily
   *    and then change it back to the original when all is done.

   * 2. If the pgmType in the function call is the same.
   *    In this case, just proceed as normal.
   */

  // 1. If the pgmType in the function call is not the same
  if (image.pgmType != pgmType) {
    std::string pgmTypeBackup = image.pgmType;
    image.pgmType = pgmType;

    // Save as a file
    pgmSaveAsFile(image, fileName);

    // Restore the original pgmType
    image.pgmType = pgmTypeBackup;
  }

  // 2. If the pgmType in the function call is the same.
  else if (image.pgmType == pgmType) {
    // Save as a file
    pgmSaveAsFile(image, fileName);
  }
}

void readFileAndPrintWhiteSpaces(std::string fileName) {
  /*
   *  A function for printing all whitespaces in a file.
   *  This function is used only for debugging.
   */
  std::ifstream file{fileName, std::ios_base::binary};
  if (!file) {
    throw std::runtime_error("[ERROR] Can't open the file.\n");
    return;
  }

  int8_t value;
  void *valueAddress = &value;
  while (file.read(static_cast<char *>(valueAddress), sizeof(char))) {
    if (value == ' ') {
      std::cout << "*";
    } else if (value == '\n') {
      std::cout << "^";
    } else
      std::cout << value;
  }
}
