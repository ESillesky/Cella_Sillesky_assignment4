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
  void destroy(NodeType<T>* root);
  void insert(NodeType<T>*& tree, T &key);
  void deleteItem(NodeType<T>*& root, T &key);
  void retrieve(NodeType<T>*& root, T &item, bool &found) const;
  void preOrder(NodeType<T>*& root) const;
  void inOrder(NodeType<T>*& root) const;
  void postOrder(NodeType<T>*& root) const;
  int getLength(NodeType<T>*& root) const;
  void printTree(NodeType<T>*& root);
  //getNumSingleParent();
  //getNumLeafNodes();
  int getSumOfSubtrees(NodeType<T>*& node);
  NodeType<T>* getRoot();
  int getNumLeafNodes(NodeType<T>* root);
private:
  NodeType<T> *root; //not sure if right
};
