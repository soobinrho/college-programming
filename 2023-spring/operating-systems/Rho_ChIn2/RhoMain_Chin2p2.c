/*
 *    COSC 310: Operating Systems
 *    Soobin Rho
 *    February 12, 2022
 *    Hw2: Two Arrays
 */ 

#include <stdio.h>
#include "RhoSub_Chin2p2.h"

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


