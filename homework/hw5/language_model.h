//Samuel Jin
//sjin16

//language_model.h
//Header file for functions
#include <vector>
#include <string>
#include <fstream>

//Checks to see if arguments provided are valid. Returns operation value
//a = 11, c = 12, d = 13, f = 14. Returns 1 if error
int argcheck(int argc, char* argv[]);

//Generates vector of all the strings separated by a white space
void wordsep(std::ifstream &ifile, std::vector<std::string> &vect);
