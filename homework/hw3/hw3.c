//Samuel Jin
//sjin16
//hw3.c

//Implements functions and forms user interface.
#include "dnasearch.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Please enter a file name in command line");
    return 1; //indicate error
  }
  char seqarray[15001];
  
  char *fname = argv[1];
  FILE* input = fopen(fname, "r");

  if (input == NULL) {
    printf("Error: could not open input file\n");
    return 1; //indicate error
  }

  
