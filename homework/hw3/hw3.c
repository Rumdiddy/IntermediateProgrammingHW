//Samuel Jin
//sjin16
//hw3.c

//Implements functions and forms user interface.
#include "dnasearch.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int scanres;
  char allp[15000];
  char x;
  int spacer;
  int counter = 0;
  char seqarray[15000];

  //checks for file name argument
  if (argc != 2) {
    printf("Please enter a file name in command line");
    return 1; //indicate error
  }

  char *fname = argv[1];
  FILE* filep = fopen(fname, "r");

  //checks if file pointer exists
  if (filep == NULL) {
    printf("Error: could not open input file\n");
    return 1; //indicate error
  }
  
  int valarray = makearr(seqarray, filep);

  //checks if text is valid using makearr function
  if (valarray == -1) {
    printf("Invalid text\n");
    return 1; //indicate error
  }

  fclose(filep);

  int EOFhappen = 0;
  char pattern[15000];
 
  //loops as long as character is read from stdin and not EOF
  while (((scanres = scanf(" %s", pattern)) == 1)) {
    counter = strlen(pattern);
    
    //check if pattern is valid 
    int pval = pcheck(pattern, counter, valarray);
    if (pval == -1) {
      printf("Invalid pattern\n");
      return 1; //indicate error 
    }

    //performs pattern match over entire array 
    int* poffset = total_offset(seqarray, pattern);
    
    
    for (int j = 0; j < counter; j++) {
      printf("%c", pattern[j]);
    }
    printf(" ");
    
    //prints out the offset array
    int outres = totalout(poffset);
    
    if (outres == -1) { 
      return 1; //indicate error
    }
    printf("\n");       
  }
  
  //printf("%d", scanres);
  return 0;
}
