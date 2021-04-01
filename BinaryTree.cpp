#include "BinaryTree.h"

using namespace std;

//Pre-Condition: None.
//Post-Condition: Tree is initialized.
//Coded by: Eliza Sillesky
template <class T>
BinaryTree<T>::BinaryTree() {
  root = nullptr;  
}

//Pre-Condition: Tree has been initialized.
//Post-Condition: All node pointers freed and root points to null
//Coded by: Gian Cella
template <class T>
BinaryTree<T>::~BinaryTree(){
  destroy(root);
}

//Helper method to iterate through tree and delete members + root
//Coded by: Gian Cella
template <class T>
void BinaryTree<T>::destroy(NodeType<T>* root) {
  if (root != NULL) {
    destroy(root->left); //delete left members of tree
    destroy(root->right); //delete right members of tree
    delete root; //delete root last
  }
}

//Pre-Condition: Tree and parameter key initialized.
//Post-Condition: Insert a node with the value of key into the tree. 
//No duplicates are allowed.
//Coded by: Eliza Sillesky
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
      node = new NodeType<T>;
      node->left = NULL;
      node->right = NULL;
      node->key = key;
    }
    else if (node->key >= key) {
      insert(node->left,key);
    } 
    else {
      insert(node->right,key);
    }
  }
}

template <class T>
void BinaryTree<T>::deleteItem(T &key) {

}

//Pre-Condition: Tree, item, and found are all initialized.
//Post-Condition: item should refer to a key of a Node n in the tree where the value of n.key is equal to 
//the value of item and found should be equal to true if n exists. Otherwise found should be equal to false.
//Coded by: Gian Cella
template <class T>
void BinaryTree<T>::retrieve(NodeType<T>* root, T &item, bool &found) const {
  if(root == NULL) {
    found = false; //item not found in the tree
  }
  else if(item < root->key) { //compares item with each node
    retrieve(root->left, item, found); //less than go to left
  }
  else if(item > root->key) { //compares item with each node
    retrieve(root->right, item, found); //greater than go to right
  }
  else {
    item = root->key; //item and current node are equal
    found = true; //item was found
  }
}

//Pre-Condition: The tree has been initialized.
//Post-Condition: Print out the tree in pre-order.
//Coded by: Gian Cella
template <class T>
void BinaryTree<T>::preOrder(NodeType<T>* root) const {
  if(root != NULL){
    cout << root->key << " "; //node
    preOrder(root->left); //left subtree
    preOrder(root->right); //right subtree
  }
  else {
    return;
  }
}

//Pre-Condition: The tree has been initialized.
//Post-Condition: Print out the tree in in-order.
//Coded by: Gian Cella
template <class T>
void BinaryTree<T>::inOrder(NodeType<T>* root) const {
  if(root != NULL){
    inOrder(root->left); //left subtree
    cout << root->key << " "; //node
    inOrder(root->right); //right subtree
  }
}

//Pre-Condition: The tree has been initialized.
//Post-Condition: Print out the tree in post-order.
//Coded by: Gian Cella
template <class T>
void BinaryTree<T>::postOrder(NodeType<T>* root) const {
  if(root != NULL){
    postOrder(root->left); //left subtree
    postOrder(root->right); //right subtree
    cout << root->key << " "; //node
  }
}

//Pre-Condition: The tree has been initialized.
//Post-Condition: Return the value of length of the BST. 
//(same as the method discussed in the class)
//Coded by: Gian Cella
template <class T>
int BinaryTree<T>::getLength(NodeType<T>* root) const {
  if(root == NULL) { //nothing in the tree
    return 0;
  }
  else {
    return getLength(root->left) + getLength(root->right) + 1; //all members plus the root
  }
}

//This function should count the number of leaf nodes in the BST 
//(Nodes with no children) and then output the count
//Coded by: Gian Cella
template <class T>
int BinaryTree<T>::getNumLeafNodes(NodeType<T>* root) {
  if(root == NULL) { //nothing in the tree
    return 0;
  }
  if(root->left == NULL && root->right == NULL) {
    return 1; //no left or right subtree
  }
  return getNumLeafNodes(root->left) + getNumLeafNodes(root->right); //add 1 for all leaf members
}

//Helper method to get the root of a tree.
//Coded by: Eliza Sillesky
template <class T>
NodeType<T>* BinaryTree<T>::getRoot() {
  return root;
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;
