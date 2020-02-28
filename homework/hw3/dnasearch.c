//Samuel Jin
//sjin16
//dnasearch.c

//Implementation of functions listed in dnasearch.h
#include "dnasearch.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Returns the first pattern offset beginning at start_at. Returns -1
//if there is no pattern found.
int pattern_match(const char t[], int tlen, const char p[], int plen, int start_at) {
  int match;
  for(int i = start_at; i <= (tlen - plen); i++) {
    match = 1;
    for(int j = 0; j < plen; j++) {
      if (t[i + j] != p[j]) {
        match = 0;
        break;
      }
    }
    if (match != 0) {
      return i;
    }
  }
  return -1;
}

//Returns an array of all offsets of pattern.
int* total_offset(const char t[], const char p[]) {
  int plen = strlen(p);
  int tlen = strlen(t);
  int *occ = malloc(sizeof(int) * 15001);
  int ind = 0;
  int j;
  int count = 0;
  while ((j = pattern_match(t, tlen, p, plen, ind)) != -1) {
    occ[count] = j;
    ind = j + 1;
    count += 1;
  }
  occ[count] = -1;
  int *occ_new = realloc(occ, sizeof(int) * count);
  return occ_new;
}

//Prints out all elements of the offset array. Then frees the array.
int totalout(int* arr) {
  if (arr[0] == -1) {
    printf("Not found\n");
    free(arr);
    return -1;
  }
  for (int i = 0; i < 15001; i++) {
    if (arr[i] == -1) {
      break;
    }
    printf("%i ", arr[i]);
  }
  printf("\n");
  free(arr);
  return 1;
}  
   
//Creates all uppercase sequence array from text file. Ensures sequence
// from file is valid.
int makearr(char seqarray[], FILE* filep) {
  char letter;
  int scanres;
  int count = 0;
  
  while ((scanres = fscanf(filep, " %c ", &letter)) == 1) {
    letter = toupper(letter);

    switch(letter) {
    case 'A':
      seqarray[count] = 'A';
      count+=1;
      break;
    case 'C':
      seqarray[count] = 'C';
      count+=1;
      break;
    case 'G':
      seqarray[count] = 'G';
      count+=1;
      break;
    case 'T':
      seqarray[count] = 'T';
      count+=1;
      break;
    default:
      return -1;
    }
  }

  if (count <= 0 || count > 15000) {
    return -1;
  } else {
    return count;
  }  
}

//Checks if pattern is valid by checking length. Makes pattern case insensitive
int pcheck(char p[], int sizep, int sseq) {
  char letter;
  
  if (sizep > sseq) {
    return -1;
  }
  
  for (int i = 0; i < sizep; i++) {
    letter = p[i];
    letter = toupper(letter);
    
    switch(letter) {
    case 'A':
      p[i] = 'A';
      break;
    case 'C':
      p[i] = 'C';
      break;
    case 'G':
      p[i]  = 'G';
      break;
    case 'T':
      p[i]  = 'T';
      break;
    default:
      return -1; 
    }
  }
  return 1;
}
