//Samuel Jin
//sjin16

//hw5.cpp
#include <iostream>
#include "language_model.h"
#include <fstream>
#include <vector>
#include <string.h>
#include <map>
#include <stdio.h>

using std::cout; using std::endl;
using std::ifstream; using std::string;
using std::vector; using std::cerr; using std::map;

int main(int argc, char* argv[]) {

  //Runs argument checker function
  int operval = argcheck(argc, argv);
  if (operval == 1) {
    return 1;
  }
  
  //Checks if file list can be opened
  ifstream iflist(argv[1]);
  if (!iflist.is_open()) {
    std::cerr << "Invalid file list: " << argv[1] << endl;
    return 1;
  }

  //Checks if files within file list are openable
  string fn;
  vector<string> allword;
  while(iflist >> fn) {
    ifstream ifile(fn);
    if (!ifile.is_open()) {
      std::cerr << "Invalid file: " << fn << endl;
      return 1;
    }

    //Generates vector with words
    wordsep(ifile, allword);
  }
 
  //Creates map of the trigrams
  map<vector<string>, int> trivals = gentrigram(allword);

  switch(operval) {
  case 11: //a
    for(map<vector<string>, int>::const_iterator i = trivals.begin(); i != trivals.end(); ++i){
      std::cout << i->second << " - [";
      for (vector<string>::const_iterator j = i->first.cbegin(); j != i->first.cend(); ++j) {
	std::cout << *j << " ";
      }
      std::cout << '\b';
      std::cout << "]" << endl;    
    }
    break;
  case 13: //d
    for(map<vector<string>, int>::reverse_iterator i = trivals.rbegin(); i != trivals.rend(); ++i) {
      std::cout << i->second << " - [";
      for (vector<string>::const_iterator j = i->first.cbegin(); j != i->first.cend(); ++j) {
	std::cout << *j << " ";
      }
      std::cout << '\b';
      std::cout << "]" << endl;
    }
    break;
  case 12: //c
    outmapc(trivals);
    break;
  case 14: //f

    break;
  }
  return 0;
}
