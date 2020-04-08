//Samuel Jin
//sjin16

//hw5.cpp
#include "language_model.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>

using std::cout; using std::endl;
using std::ifstream; using std::string;
using std::vector; using std::cerr;

int main(int argc, char* argv[]) {

  //Runs argument checker function
  int operval = argcheck(argc, argv);
  if (operval == 1) {
    return 1;
  }
  
  //Checks if file list can be opened
  ifstream iflist(argv[1]);
  if (!iflist.is_open()) {
    cerr << "Invalid file list: " << argv[1] << endl;
    return 1;
  }

  //Checks if files within file list are openable
  string fn;
  vector<string> allword;
  while(iflist >> fn) {
    ifstream ifile(fn);
    if (!ifile.is_open()) {
      cerr << "Invalid file: " << fn << endl;
      return 1;
    }

    //Generates vector with words
    wordsep(ifile, allword);
  }

  for(int i = 0; i < (int)allword.size(); i++) {
      std::cout << allword.at(i) << endl;
  }
  
  return 0;
}
