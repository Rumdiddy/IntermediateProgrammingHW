//Samuel Jin
//sjin16

//language_model.cpp
//Implementation of all functions in language_model.h

#include "language_model.h"
#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using std::cerr; using std::endl; 
using std::string; using std::vector;
using std::ifstream; using std::cout;

//Checks to see if arguments provided are valid. Returns operation value
//a = 11, c = 12, d = 13, f = 14. Returns 1 if error
int argcheck(int argc, char* argv[]) {

  //Checks for file list argument
  if (argc < 2) {
    cerr << "Invalid file list: " << argv[1] << endl;
    return 1;
  }

  //Checks if valid operation provided
  int oper;
  if (strcmp(argv[2], "a") == 0) {
    oper = 11;
  } else if (strcmp(argv[2], "c") == 0) {
    oper = 12;
  } else if (strcmp(argv[2], "d") == 0) {
    oper = 13;  
  } else if (strcmp(argv[2], "f") == 0) {
    oper = 14;
  } else {
    cerr << "Invalid command: valid options are a, d, c, and f" << endl;
    return 1;
  }

  //Checks if two additional arguments provided for f
  if (oper == 14) {
    if (argc < 5) {
      cerr << "Invalid argument list: f requires two additional command-line arguments" << endl;
      return 1;
    }
  }
  return oper;
}

//Generates vector of all the strings separated by a white space
void wordsep(ifstream &ifi, vector<string> &vect) {

  //Adds <Start_1> and <Start_2> 
  string word1 = "<START_1>";
  string word2 = "<START_2>";
  vect.push_back(word1);
  vect.push_back(word2);

  //Keeps reading words from inut file stream and storing to vector
  string iword;
  while (ifi >> iword) {
    vect.push_back(iword);    
  }

  //Adds <END_#> to the vector
  word1 = "<END_1>";
  word2 = "<END_2>";
  vect.push_back(word1);
  vect.push_back(word2);
}


