//Samuel Jin
//sjin16
//dnasearch.c

//Implementation of functions listed in dnasearch.h
#include "dnasearch.h"
#include <string.h>

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
  return occ;
}


