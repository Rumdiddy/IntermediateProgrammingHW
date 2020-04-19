//Samuel Jin
//sjin16
//Tree.h

#ifndef _TREE_H
#define _TREE_H

#include <cstdlib>
#include <string>

// Template Tree Class
template<typename T>
class Tree {
  friend class TTreeTest;
  
  T data;     // the value stored in the tree node

  Tree<T> * kids;  // children - pointer to first child of list, maintain order & uniqueness

  Tree<T> * sibs;  // siblings - pointer to rest of children list, maintain order & uniqueness
                 // this should always be null if the object is the root of a tree

  Tree<T> * prev;  // pointer to parent if this is a first child, or left sibling otherwise
                 // this should always be null if the object is the root of a tree

 public:
  template<typename S>
  friend std::ostream& operator<<(std::ostream& os, Tree<S>& rt);
  Tree<T>(T inp);

  ~Tree();  // clear siblings to right and children and this node
  
  Tree& operator^(Tree<T>& rt);  //^ operator to do the same thing as addChild
  bool operator==(const Tree<T> &root); // return true if two CTrees match node by node
  
  // siblings and children must be unique, return true if added, false otherwise
  bool addChild(T inp);

  // add tree root for better building, root should have null prev and sibs 
  // returns false on any type of failure, including invalid root
  bool addChild(Tree<T> *root);

  std::string toString(); // all characters, separated by newlines, including at the end

  
 private:
  // these should only be called from addChild, and have the same restrictions
  // the root of a tree should never have any siblings
  // returns false on any type of failure, including invalid root
  bool addSibling(T inp);
  bool addSibling(Tree<T> *root);

};

#include "Tree.inc"
#endif
