#include "BinaryTree.h"

using namespace std;

string command;
string line; //line from input text                                             
string token; //individual elements

template <class T>
void runCommands(BinaryTree<T> tree){

  NodeType<T> * root = tree.getRoot();

  do {

    cout << "\nEnter a command: ";
    cin >> command;
    cout << endl;
    
    if(command == "q") {
      cout << "Quitting program...\n" << endl;
      cout << endl;
      exit(1);
    }
    else if(command == "i") {
      T key;
      cout << "Item to insert: ";
      cin >> key;
      cout << endl;
      tree.insert(root, key);
      cout << "In-Order: ";
      tree.inOrder(root);
      cout << endl;
      cout << endl;
    }
    else if(command == "d") {
      T item;
      cout << "Item to delete: ";
      cin >> item;
      cout << endl;
      tree.deleteItem(root, item);
      cout << "In-Order: ";
      tree.inOrder(root);
      cout << endl;
      cout << endl;
    }
    else if(command == "l") {
      cout << "Tree Length: " << tree.getLength(root) << endl;
      cout << endl;
    }
    else if(command == "r") {
      T key;
      bool found;
      cout << "Item to retrieve: ";
      cin >> key;
      cout << endl;
      tree.retrieve(root, key, found);
      if(found == true) {
        cout << "Item found in tree." << endl;
        cout << endl;
      }
      else {
        cout << "Item not in tree." << endl;
        cout << endl;
      }
    }
    else if(command == "n") {
      cout << "In-Order: ";
      tree.inOrder(root);
      cout << endl;
      cout << endl;
    }
    else if(command == "p") {
      cout << "Pre-Order: ";
      tree.preOrder(root);
      cout << endl;
      cout << endl;
    }
    else if(command == "o") {
      cout << "Post-Order: ";
      tree.postOrder(root);
      cout << endl;
      cout << endl;
    }
    else if(command == "s") {    
      //tree.getNumSingleParent();
    }
    else if(command == "f") {
      cout << "Number of leaf nodes: " + tree.getNumLeafNodes(root) << endl;
      cout << endl;
    }
    else if(command == "t") {
      //tree.getSumOfSubtrees();                                                               
    }
    else {
      cout << "Command not recognized. Try again" << endl; //wrong command  
      cout << endl;          
    }
  }
  while(command != "q"); //repeat until user types 'q'                          
}

int main(int argc, char *argv[]) {

  BinaryTree<std::string> stringTree;
  BinaryTree<int> intTree;
  BinaryTree<float> floatTree;
  ifstream inputFile(argv[1], ios::in);
  NodeType<string> * stringRoot = nullptr;
  NodeType<int> * intRoot = nullptr;
  NodeType<float> * floatRoot = nullptr;

  if(!inputFile){ //error if file not found                                     
    cout << "Failed to open the input file" << endl;
    exit(1);
  }
  else {
    string treeType;
    cout << "\nEnter tree type (i - int, f - float, s - std::string): ";
    cin >> treeType;
    cout << endl;
    cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o)" << endl;
    cout << "getNumSingleParent (s), getNumLeafNodes (f), getSumOfSubtrees (t), quit (q)" << endl;
    cout << endl;
    if(treeType == "s" || treeType == "i" || treeType == "f") {
      if (treeType == "s") {
        getline(inputFile, line); //converts file to string                                                       
        istringstream iss(line);
        if(line != " ") { //if file not empty                                                                     
          while(getline(iss, token, ' ')){
            string item = token;
	          stringTree.insert(stringRoot,item); //added to list
          }
        }
        runCommands(stringTree);
      }   
      else if (treeType == "i") { //int
	      getline(inputFile, line); //converts file to string                                                       
	      istringstream iss(line);
	      if(line != " ") { //if file not empty                                                                     
	        while(getline(iss, token, ' ')){
	          int item = stoi(token);
	          intTree.insert(intRoot,item); //added to list                                                             
	        }
	      }
	      runCommands(intTree);
      }
      else if (treeType == "f") { //float                                                                         
        getline(inputFile, line); //converts file to string                                                       
	      istringstream iss(line);
        if(line != " ") { //if file not empty                                                                     
          while(getline(iss, token, ' ')){
            float item = stof(token);
            floatTree.insert(floatRoot,item); //added to list                                                           
          }
	      }
	      runCommands(floatTree);
      }
    }
    else {
      cout << "Invalid Input" << endl;
      cout << endl;
      exit(1);
    }
  }
}
