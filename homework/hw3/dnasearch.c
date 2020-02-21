//Samuel Jin
//sjin16
//dnasearch.c

//Implementation of functions listed in dnasearch.h
#include "dnasearch.h"

//Returns the first pattern offset beginning at start_at. Returns -1
//if there is no pattern found.
int pattern_match(const char t[], int tlen, const char p[], int plen, int start_at) {
  int match;
  for(int i = start_at; i <= (tlen - plen); i++) {
    match = 1;
    for(int j = 0; j <= plen; j++) {
      if (p[j] != t[i + j]) {
	match = 0;
	break;
      }
    }
    if (match != 0) {
      return i;
    }     
  }
}
