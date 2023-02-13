/*
 *    COSC 310: Operating Systems
 *    Soobin Rho
 *    February 12, 2022
 *    Hw2: Two Arrays
 */ 

#include <stdio.h>

void addArrays(int* arrSum, int* arr1, int* arr2, int SIZE);
void printArray(int* arr, int SIZE);

int main() {
  // ------------------------------------------------------------------
  // Get user input
  // ------------------------------------------------------------------
  printf("Enter the size of each array: ");
  int SIZE;
  scanf("%d",&SIZE);

  printf("\nType two integer arrays of size %d.\n",SIZE);
  printf("Example:\n");
  printf("  1 3 2 5 2\n");
  printf("  5 9 6 8 4\n\n");

  printf("ARRAY 1\n");
  int arr1[SIZE];
  int i;
  for (i=0;i<SIZE;++i) {
    printf("Enter an integer (%d out of %d): ",i+1,SIZE);
    scanf("%d",&arr1[i]);
  }

  printf("\nARRAY 2\n");
  int arr2[SIZE];
  for (i=0;i<SIZE;++i) {
    printf("Enter an integer (%d out of %d): ",i+1,SIZE);
    scanf("%d",&arr2[i]);
  }

  // ------------------------------------------------------------------
  // Create a new array with the sum of both arrays
  // ------------------------------------------------------------------
  int arrSum[SIZE];
  addArrays(arrSum,arr1,arr2,SIZE);

  // ------------------------------------------------------------------
  // Print the arrays
  // ------------------------------------------------------------------
  printf("\nRESULTS\n");
  printf("=======\n");

  printf("\nARRAY 1\n");
  printArray(arr1,SIZE);

  printf("\nARRAY 2\n");
  printArray(arr2,SIZE);

  printf("\nSUM ARRAY\n");
  printArray(arrSum,SIZE);

  return 0;
}

void addArrays(int* arrSum, int* arr1, int* arr2, int SIZE) {
  int i;
  for (i=0;i<SIZE;++i) {
    arrSum[i] = arr1[i]+arr2[i];
  }
}

void printArray(int* arr, int SIZE) {
  int i;
  for (i=0;i<SIZE;++i) {
    printf("%d ",arr[i]);
  }
  printf("\n");
}
