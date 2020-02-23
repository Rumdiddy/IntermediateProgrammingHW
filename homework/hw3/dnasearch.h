//Samuel Jin
//sjin16

//All function declarations go here. Implemented in dnasearch.c

//Return value is first offset ( >= start_at) of pattern.
//Returns -1 if no such occurence. *Similar to Java indexOf()*
int pattern_match(const char t[], int tlen, const char p[], int plen, int start_at);

//Utilizes pattern_match() to find all occurrences of pattern.
//Returns array of offsets.
int * total_offset(const char t[], const char p[]);


