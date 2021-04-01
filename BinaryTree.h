#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <sstream>

using namespace std;

template <class T>
struct NodeType {
  T key;
  NodeType<T> *left;
  NodeType<T> *right;
};

template <class T>
class BinaryTree {
public:
  BinaryTree();
  ~BinaryTree();
  void insert(NodeType<T>*& tree, T &key);
  void deleteItem(T &key);
  void retrieve(T &item, bool &found) const;
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  int getLength() const;
  void printTree(NodeType<T>*& root);
  //getNumSingleParent();
  //getNumLeafNodes();
  //getSumOfSubtrees();
  NodeType<T>* getRoot();  
 private:
  NodeType<T> *root; //not sure if right
};
