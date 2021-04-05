Gian Cella
gpc46003@uga.edu

Contribution:
*void destroy(NodeType<T>* root);
*void deleteItem(NodeType<T>*& root, T &key);
*void retrieve(NodeType<T>* root, T &item, bool &found) const;
*void preOrder(NodeType<T>* root) const;
*void inOrder(NodeType<T>* root) const;
*void postOrder(NodeType<T>* root) const;
*int getNumLeafNodes(NodeType<T>* root);
*Split main.cpp and BinaryTree.h

Eliza Sillesky
els95861@uga.edu

Contribution:
*void insert(NodeType<T>*& node, T &key);
*void getNumSingleParent(NodeType<T>* root);
*void getSumOfSubtrees(NodeType<T>* root);
*NodeType<T>* getRoot(); 
*int getLength(NodeType<T>* root) const; 
*void printTree(NodeType<T>*& root)
*Split main.cpp and BinaryTree.h



Instructions:
Cella_Sillesky_assignment4$ make (uses the makefile to create .o files)
Cella_Sillesky_assignment4$ ./main int-input1.txt (converts the text file to a list of integers)
Cella_Sillesky_assignment4$ ./main float-input1.txt (converts the text file to a list of floating point numbers)
Cella_Sillesky_assignment4$ ./main string-input1.txt (converts the text file to a list of std::strings)
Cella_Sillesky_assignment4$ make clean (removes .o files and main executable)



Number of Leaf Nodes Function:

template <class T>
int BinaryTree<T>::getNumLeafNodes(NodeType<T>* root) {  
  if(root == NULL) {  <----------------------------------------------------  1
    return 0;  <-----------------------------------------------------------  1
  }
  if(root->left == NULL && root->right == NULL) {  <-----------------------  1
    return 1;  <-----------------------------------------------------------  1
  }
  return getNumLeafNodes(root->left) + getNumLeafNodes(root->right);  <----  n
}

Time Complexity: 
T(n) <= T(n - 1) + (n + 1), if n > 1
T(n) <= 0, if n = 0
T(n) <= 1, if n = 1
c = 0, 1
a = 0

1 + 1 + 1 + 1 + n
= 4 + n
Big-O (Worst Case):
If complexity is a polynomial, variable with highest exponent is the worst case scenario.
Notation would be O(n) due to the majority of the code being if-else statements that do not change complexity.
Recursion, in this case, would be complexity of n due to iterating through each node and left and right subtrees.

int BinaryTree<T>::getNumSingleParent(NodeType<T>* root) {;

  // base case                                                                             
  if (root == NULL) {  <----------------------------------------------------  1
    return 0;         <----------------------------------------------------  1
  }
  getNumSingleParent(root->left);   <----------------------------------------------------  T(n/2)
  getNumSingleParent(root->right);   <----------------------------------------------------  T(n/2)

  return isSingleParent(root) + (getNumSingleParent(root->left) + getNumSingleParent(root->right));   <————————— T(n/2) + T(n/2)

}
Time complexity:
T(n) = T(n/2) + T(n/2) + T(n/2) + T(n/2)

Big-O (Worst Case):
If complexity is a polynomial, variable with highest exponent is the worst case scenario. Notation would be O(n) due to the majority of the code being if-else statements that do not change complexity. Recursion, in this case, would be complexity of n due to iterating through each node and left and right subtrees.

template <class T>
T BinaryTree<T>::getSumOfSubtrees(NodeType<T>*& node) {

  //base case                                                                              
  if (node == nullptr) {    <----------------------------------------------------  1
    return 0;  <----------------------------------------------------  1
  }


  if(addNode){  <----------------------------------------------------  1
    return node->key + getSumOfSubtrees(node->right) + getSumOfSubtrees(node->left);  <——————————————— T(n/2) + T(n/2)
  }else{
    addNode = true;                            <----------------------------------------------------  1
    T sum = getSumOfSubtrees(node->right) + getSumOfSubtrees(node->left); <——————————————— T(n/2) + T(n/2)
    addNode = false;  <----------------------------------------------------  1
    return sum;  <----------------------------------------------------  1

  }

}

Time complexity:
T(n) = T(n/2) + T(n/2) + T(n/2) + T(n/2) + 6

Big-O (Worst Case):
If complexity is a polynomial, variable with highest exponent is the worst case scenario. Notation would be O(n) due to the majority of the code being if-else statements that do not change complexity. Recursion, in this case, would be complexity of n due to iterating through each node and left and right subtrees.



