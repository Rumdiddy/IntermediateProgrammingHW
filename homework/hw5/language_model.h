//Samuel Jin
//sjin16

//language_model.h
//Header file for functions
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <iostream>

//Checks to see if arguments provided are valid. Returns operation value
//a = 11, c = 12, d = 13, f = 14. Returns 1 if error
int argcheck(int argc, char* argv[]);

//Generates vector of all the strings separated by a white space
void wordsep(std::ifstream &ifile, std::vector<std::string> &vect);

//Creates trigrams of passed vector of strings and stores into a map based on occurrences
std::map<std::vector<std::string>, int> gentrigram(std::vector<std::string> &vect);

//Takes in pair of vector<string> and int and sorts based on the int value. Comparator
bool sortfunct(const std::pair<std::vector<std::string>, int> &s1, const std::pair<std::vector<std::string>, int> &s2);

//Sorts passed in map based on int values and outputs in order. Operation c
void outmapc(std::map<std::vector<std::string>, int> &mapad);

//Runs through the entire word vector and checks for how many times that third word occurs
void outf(std::map<std::vector<std::string>, int> &mapad, std::string s1, std::string s2);
