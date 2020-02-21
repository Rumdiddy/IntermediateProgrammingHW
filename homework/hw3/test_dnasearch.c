//Samuel Jin
//sjin16
//dnasearch.c

//Contains main function that tests each function in dnasearch.c. USE ASSERT
#include "dnasearch.h"

/*
 * Reads lhs and rhs character by character until either reaches eof.
 * Returns true if the files can be read and the two files match
 * character by character. Returns false if two files either can't be
 * opened or don't match.
 */
int fileeq(char lhsName[], char rhsName[]) {
    FILE* lhs = fopen(lhsName, "r");
    FILE* rhs = fopen(rhsName, "r");

    // don't compare if we can't open the files
    if (lhs == NULL || rhs == NULL) return 0;

    int match = 1;
    // read until both of the files are done or there is a mismatch
    while (!feof(lhs) || !feof(rhs)) {
        if (feof(lhs) ||                  // lhs done first
            feof(rhs) ||                  // rhs done first
            (fgetc(lhs) != fgetc(rhs))) { // chars don't match
            match = 0;
            break;
        }
    }
    fclose(lhs);
    fclose(rhs);
    return match;
}
