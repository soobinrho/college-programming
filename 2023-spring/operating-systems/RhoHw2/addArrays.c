#include "addArrays.h"

void addArrays(int* arrSum, int* arr1, int* arr2, int SIZE) {
  int i;
  for (i=0;i<SIZE;++i) {
    arrSum[i] = arr1[i]+arr2[i];
  }
}
