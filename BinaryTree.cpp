#include "BinaryTree.h"

using namespace std;
bool addNode = false;

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
  bool found;

  //check if node is in tree already
  retrieve(node, key, found);

  if (found != 0) {
    cout << "Item already in tree." << endl;
    return;
  }

  //insert head
  if(root == nullptr){
    root = new NodeType<T>;
    root->left = NULL;
    root->right = NULL;
    root->key = key;
    node = root;
  }
  else{

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

//Pre-Condition: Tree and parameter key initialized.
//Post-Condition: Remove a node with a key value equal to the parameter key’s value otherwise 
//leave the tree unchanged (if the key is not present). In situations, where the node to be deleted 
//has two children, replace the deleted node with its immediate predecessor or successor.
//Coded by: Gian Cella
template <class T>
void BinaryTree<T>::deleteItem(NodeType<T>*& root, T &key) {
  T data;
  NodeType<T>* tempPtr;
  tempPtr = root;
  bool found;
  retrieve(root, key, found);
  if(root == nullptr){ //empty tree
    return; 
  }
  else if(found == false) {
    cout << "Item not in tree." << endl;
    cout << endl;
  }
  else{
    if(key < root->key) { //move to left subtree
      deleteItem(root->left, key); //key less than
    }
    else if(key > root->key) { //move to right subtree
      deleteItem(root->right, key); //key greater than
    }
    else {
      if(root->left == NULL){ //no left subtree
        root = root->right;
        delete tempPtr;
      }
      else if(root->right == NULL){ //no right subtree
        root = root->left;
        delete tempPtr;
      }
      else{
        while((root->left)->right != NULL) { //predecessor
          (root->left) = (root->left)->right;
        }
        data = (root->left)->key; //input pred
        root->key = data; //removes old data
        deleteItem(root->left, data);
      }
    }
  }
}

//Pre-Condition: Tree, item, and found are all initialized.
//Post-Condition: item should refer to a key of a Node n in the tree where the value of n.key is equal to 
//the value of item and found should be equal to true if n exists. Otherwise found should be equal to false.
//Coded by: Gian Cella
template <class T>

void BinaryTree<T>::retrieve(NodeType<T>*& root, T &item, bool &found) const {
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

void BinaryTree<T>::preOrder(NodeType<T>*& root) const {

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
//Coded by: Gian Cella/Eliza Sillesky
template <class T>

void BinaryTree<T>::inOrder(NodeType<T>*& root) const {

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

void BinaryTree<T>::postOrder(NodeType<T>*& root) const {

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

int BinaryTree<T>::getLength(NodeType<T>*& root) const {

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


template <class T>
void BinaryTree<T>::printTree(NodeType<T>*& root) {

  if (root == nullptr) {
    return;
  }
  printTree(root->left);
  cout << root->key << " ";
  printTree(root->right);

}

//Coded by: Eliza Sillesky

//gets sum of subtrees, not including inserted node
template <class T>
T BinaryTree<T>::getSumOfSubtrees(NodeType<T>*& node) {

  //base case
  if (node == nullptr) {
    return 0;
  }

  
  if(addNode){
    return node->key + getSumOfSubtrees(node->right) + getSumOfSubtrees(node->left);
  }else{
    addNode = true;
    T sum = getSumOfSubtrees(node->right) + getSumOfSubtrees(node->left);
    addNode = false;
    return sum;

  }

}

//Eliza
// Helper method for getSumOfSubtrees.
template <class T>
NodeType<T>* BinaryTree<T>::searchNode(T& key) {

  NodeType<T>* notFoundNode;
  NodeType<T>* currentNode;
  currentNode = root;
  notFoundNode = nullptr;

  //traverse through tree
  while (currentNode != nullptr) {

    // found
    if (key == currentNode->key) {
      return currentNode;
    }
    //left side
    else if (key < currentNode->key) {
      currentNode = currentNode->left;
    }
    else {
      currentNode = currentNode->right;
    }
  }
  cout << "Item not in tree. " << endl;
  return notFoundNode; 

}

//Returns number of nodes that have one child
//Eliza
template <class T>
int BinaryTree<T>::getNumSingleParent(NodeType<T>* root) {;

  // base case
  if (root == NULL) {
    return 0;
  }
  getNumSingleParent(root->left);
  getNumSingleParent(root->right);
   
  return isSingleParent(root) + (getNumSingleParent(root->left) + getNumSingleParent(root->right));   


}

//checks if node is single parent
//Eliza
template <class T>
bool BinaryTree<T>::isSingleParent(NodeType<T>* node) {

  //checks if node has a single parent or not
  if (node != NULL && (( node->left != NULL && node->right == NULL) || (node->left == NULL && node->right != NULL))) {
    return 1;
  }
  return 0;
}
  

//Helper method to get the root of a tree.
template <class T>
NodeType<T>* BinaryTree<T>::getRoot() {
  return root;
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;
