//Samuel Jin
//sjin16
//CTree.cpp

#include <cstdlib>
#include <iostream>
#include "CTree.h"
#include <string>
#include <sstream>

using std::ostream; using std::string;
using std::stringstream; using std::endl;

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
  if (kids == NULL) {
    kids = new CTree(ch);
    kids->prev = this;
    return true;
  }
  return kids->addSibling(ch);
}

//Overloaded function of addChild. Passed root pointer
bool CTree::addChild(CTree * root) {
  if (kids == NULL) {
    kids = root;
    kids->prev = this;
    return true;
  }
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
  } else if (ch > data) {
    if (sibs == NULL) {
      sibs = new CTree(ch);
      sibs->prev = this;
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
    } else if (ch > data && ch > sibs->data) {
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
    if(sibs->data > root->data) {
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

  //Stores current data into stringstream
  stringstream sstore;
  sstore << data << endl;

  //Recursion going through kids then sibs
  if (kids != NULL) {
    sstore << kids->toString();
  }
  if (sibs != NULL) {
    sstore << sibs->toString();
  }

  return sstore.str();
}

//Overloaded << operator function that displays the same value as toString()
ostream& operator<<(ostream& os, CTree& rt) {
  os << rt.toString();
  return os;
}

//Returns true if two CTrees match node by node
bool CTree::operator==(const CTree &root) { 
  if(this->data != root.data) {
      return false;
  }
  if((sibs == NULL) != (root.sibs == NULL)) {
    return false;
  }
  if((kids == NULL) != (root.kids == NULL)) {
    return false;
  }
  if((prev == NULL) != (root.prev == NULL)) {
    return false;
  }
  if((prev == NULL) && (sibs != NULL)) {
    return false;
  }
  
  if ((kids != NULL) && (root.kids != NULL)) {
    return (*kids == *(root.kids));
  } else {
    if ((sibs != NULL) && (root.sibs != NULL)) {
      return (*sibs == *(root.sibs));
    }
  }
  return true;
}
