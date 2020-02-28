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
  FILE* filep = fopen(fname, "r");

  if (input == NULL) {
    printf("Error: could not open input file\n");
    return 1; //indicate error
  }

  int valarray = makearr(seqarray, filep);
  
  if (valarray == -1) {
    printf("Invalid text\n");
    return 1; //indicate error
  }

  int scanres;
  char allp[15000];
  char x;
  int count = 0;
  printf("Please enter any number of patterns separated by whitespace.\n");

  while (((scanres = scanf("%c", x)) != EOF) && (scanres == 1)) {
    if (isspace(x)) {
      char pattern[count];

      for (int i = 0; i < count; i++) {
	pattern[i] = allp[i];
      }

      int pval = pcheck(pattern, seqarray);
      if (pval == -1) {
	printf("Invalid pattern\n");
	return 1; //indicate error
      }

      int* poffset = total_offset(seqarray, pattern);
      for (int j = 0; j < sizeof(pattern); j++) {
	printf("%c", pattern[j]);
      }
      
      int outres = totalout(poffset);
      if (outres == -1) {
	return 1;
      } 
      
    } else {
      allp[count] = x;
      count+=1;
    }
  }
}
	 
