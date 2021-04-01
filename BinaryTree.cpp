#include "BinaryTree.h"
#include <string>

using namespace std;

template <class T>
BinaryTree<T>::BinaryTree() {
  root = nullptr;
  
}

template <class T>
BinaryTree<T>::~BinaryTree() {

}

template <class T>
void BinaryTree<T>::insert(NodeType<T>*& node, T &key) {

  if(root == nullptr){
    root = new NodeType<T>;
    root->left = NULL;
    root->right = NULL;
    root->key = key;
    node = root;
  }
  else{
    //base case
    //found insertion spot
    if (node == nullptr) {
      cout << "inserting: " << key << endl;
      node = new NodeType<T>;
      node->left = NULL;
      node->right = NULL;
      node->key = key;
    }
    else if (node->key >= key) {
      insert(node->left,key);
    } else {
      insert(node->right,key);
    }
  }
}

template <class T>
void BinaryTree<T>::deleteItem(T &key) {

}

template <class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const {

}

template <class T>
void BinaryTree<T>::preOrder() const {

}

template <class T>
void BinaryTree<T>::inOrder() const {
  
  
}

template <class T>
void BinaryTree<T>::postOrder() const {

}

template <class T>
int BinaryTree<T>::getLength() const {

}

template <class T>
void BinaryTree<T>::printTree(NodeType<T>*& root) {

  if (root == nullptr) {
    return;
  }
  printTree(root->left);
  cout << root->key << " ";
  printTree(root->right);
  
}

template <class T>
NodeType<T>* BinaryTree<T>::getRoot() {
  return root;
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;
