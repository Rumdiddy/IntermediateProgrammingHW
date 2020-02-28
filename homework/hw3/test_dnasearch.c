//Samuel Jin
//sjin16
//test_dnasearch.c

//Contains main function that tests each function in dnasearch.c. USE ASSERT
#include "dnasearch.h"
#include "dnasearch.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int pmatchres;
  int* totaloffsetarr;
  int makearrres;
  int outputres;
  int pcheck;

  //SEE README.txt!
  //TODO: CREATE + WRITE TO FILE HERE.

  const char pattern[] = "   ag gt gT ACC";
  
  assert((makearrres = makearr(seqarray, filep)) != -1);
  assert((pcheck = pcheck(pattern, plen, makearrres)) != -1);
  assert((pmatchres = pattern_match(seqarray, makearrres, pattern, plen, 0)) != -1);
  totaloffsetarr = total_offset(seqarray, pattern);
  assert((outputres = totalout(totaloffsetarr)) == 1);
  
  const char sequence[] = "aaaagggg";
  int plen = strlen(pattern);
  int tlen = strlen(sequence);
  
  assert((pcheck = pcheck(pattern, plen, tlen)) != -1);
  assert((pmatchres = pattern_match(sequence, tlen, pattern, plen, 0)) != -1);
  

