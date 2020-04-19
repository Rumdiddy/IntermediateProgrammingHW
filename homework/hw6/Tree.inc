//Samuel Jin
//sjin16
//CTree.cpp

#include <cstdlib>
#include <iostream>
#include "Tree.h"
#include <string>
#include <sstream>

using std::ostream; using std::string;
using std::stringstream; using std::endl;

//Constructor function for node.
template<typename T>
Tree<T>::Tree(T inp) {
  data = inp;
  kids = NULL;
  sibs = NULL;
  prev = NULL;
}

//Destructor function which delets all children and siblings right of the node.
template<typename T>
Tree<T>::~Tree() {
  delete kids;
  delete sibs;
}

//Function to add a child. Passed character data for child.
template<typename T>
bool Tree<T>::addChild(T inp) {
  if (kids == NULL) {
    kids = new Tree(inp);
    kids->prev = this;
    return true;
  }
  return kids->addSibling(inp);
}

//Overloaded function of addChild. Passed root pointer
template<typename T>
bool Tree<T>::addChild(Tree<T> * root) {
  if (kids == NULL) {
    kids = root;
    kids->prev = this;
    return true;
  }
  return kids->addSibling(root); 
}
  
//Function to add a sibling. Passed character data for sibling.
template<typename T>
bool Tree<T>::addSibling(T inp) {

  //Ensure valid addition
  if (data == inp) {
    return false;
  }
  if (prev == NULL) {
    return false;
  }

  //Adds node based on case
  if (inp < data) {
    Tree<T> * temproot = prev;
    prev = new Tree(inp);
    prev->sibs = this;
    temproot->kids = prev;
    prev->prev = temproot;
    return true;
  } else if (data < inp) {
    if (sibs == NULL) {
      sibs = new Tree(inp);
      sibs->prev = this;
      return true;
    }
    if (sibs->data == inp) {
      return false;
    }
    if (inp < sibs->data) {
      sibs->prev = new Tree(inp);
      sibs->prev->prev = this;
      sibs->prev->sibs = sibs;
      sibs = sibs->prev;
      return true;
    } else if (data < inp && sibs->data < inp) {
      return sibs->addSibling(inp);
    }
  }
}

//Function that adds new root node (along with its children) as an existing sibling
template<typename T>
bool Tree<T>::addSibling(Tree<T> * root) {

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
    Tree<T> * tempr = prev;
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
    if(root->data < sibs->data) {
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
template<typename T>
Tree<T>& Tree<T>::operator^(Tree<T>& rt) {
  addChild(&rt);
  return *this;
}

//Creates a string of all characters, separated by new lines.
template<typename T>
string Tree<T>::toString() {

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
template<typename S>
ostream& operator<<(ostream& os, Tree<S>& rt) {
  os << rt.toString();
  return os;
}

//Returns true if two CTrees match node by node
template<typename T>
bool Tree<T>::operator==(const Tree<T> &root) { 
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