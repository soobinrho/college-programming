#include <stdio.h>

void printArray(int* arr, int SIZE) {
  int i;
  for (i=0;i<SIZE;++i) {
    printf("%d ",arr[i]);
  }
  printf("\n");
}
