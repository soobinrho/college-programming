/*
 *    COSC 310: Operating Systems
 *    Soobin Rho
 *    February 13, 2022
 *    Check-in 2: Function pass values
 */ 

#include <stdio.h>

int someFunction(int value, int* address);

int main() {
  int value = 1;
  int valueBackup = value;
  int returnValue = someFunction(value,&value);

  printf("originalValue = %d | value = %d | returnValue = %d",
         valueBackup,
         value,
         returnValue);

  return 0;
}

int someFunction(int value, int* address) {
  value += 10;
  *address = 25;
  return 100;
}
