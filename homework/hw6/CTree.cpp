//Samuel Jin
//sjin16
//CTree.cpp

#include <iostream>
#include "CTree.h"

using std::ostream;

//Constructor function that takes in character for node.
CTree::CTree(char ch) {
  data = ch;
  kids = NULL;
  sibs = NULL;
  prev = NULL;
}

//Destructor function which delets all children and siblings right of the node.
CTree::~CTree() {
  delete kids;
  delete sibs;
}

//Function to add a child. Passed character data for child.
bool CTree::addChild(char ch) {
    return kids->addSibling(ch);
}

//Function to add a sibling. Passed character data for sibling.
bool CTree::addSibling(char ch) {
  if (data == ch) {
    return false;
  }
  if (prev == NULL) {
    return false;
  }
  if (ch < data) {
    CTree * temproot = prev;
    prev = new CTree(ch);
    prev->sibs = this;
    temproot->kids = prev;
    prev->prev = temproot;
    return true;
  } else {
    if (sibs == NULL) {
      sibs = new CTree(ch);
      return true;
    }
    if (sibs->data == ch) {
      return false;
    }
    if (sibs->data > ch) {
      sibs->prev = new CTree(ch);
      sibs->prev->prev = this;
      sibs->prev->sibs = sibs;
      sibs = sibs->prev;
      return true;
    }
    if (sibs->data < ch) {
      return sibs->addSibling(ch);
    }
}
