//Samuel Jin
//sjin16
//CTree.cpp

#include <cstdlib>
#include <iostream>
#include "CTree.h"
#include <string>

using std::ostream; using std::string;

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

//Overloaded function of addChild. Passed root pointer
bool CTree::addChild(CTree * root) {
    return kids->addSibling(root); 
}
  
//Function to add a sibling. Passed character data for sibling.
bool CTree::addSibling(char ch) {

  //Ensure valid addition
  if (data == ch) {
    return false;
  }
  if (prev == NULL) {
    return false;
  }

  //Adds node based on case
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
    } else {
      return sibs->addSibling(ch);
    }
  }
}

//Function that adds new root node (along with its children) as an existing sibling
bool CTree::addSibling(CTree * root) {

  //Ensure not parent node or root is parent node
  if (data == root->data) {
    return false;
  }
  if (prev == NULL) {
    return false;
  }
  if (root->sibs != NULL) {
    return false;
  }
  if (root->prev != NULL) {
    return false;
  }

  //Add node as sibling
  if (root->data < data) {
    CTree * tempr = prev;
    prev = root;
    prev->sibs = this;
    tempr->kids = prev;
    prev->prev = tempr;
    return true;
  } else {
    if (sibs == NULL) {
      sibs = root;
      sibs->prev = this;
      return true;
    }
    if (sibs->data == root->data) {
      return false;
    }
    if(sibs->data > ch) {
      sibs->prev = root;
      sibs->prev->prev = this;
      sibs->prev->sibs = sibs;
      sibs = sibs->prev;
      return true;
    } else {
      return sibs->addSibling(root);
    }
  }
}

//Overloaded operator function '^' to addChild
CTree& CTree::operator^(CTree& rt) {
  addChild(&rt);
  return *this;
}

//Creates a string of all characters, separated by new lines.
string CTree::toString() {
  string temp;
  
  //Ensure start at parent node
  if (prev != NULL) {
    return prev->toString();
  }

  //Recursion going through kids then sibs
  if (kids != NULL) {
    temp = (string(1, this->data) + "\n");
    return temp.append(kids->toString());
  }
  if (sibs != NULL) {
    temp = (string(1, this->data) + "\n");
    return temp.append(sibs->toString());
  }
}

//Overloaded << operator function that displays the same value as toString()
ostream& operator<<(ostream& os, CTree& rt) {
  os << rt.toString();
  return os;
}

