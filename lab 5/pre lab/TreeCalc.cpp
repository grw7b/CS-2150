//Lab 5: Pre-Lab
//Name: Gizella Wade
//ID; grw7b
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations
///Users/gizellawade/Desktop/CS 2150/lab 5/pre lab

#include "TreeCalc.h"
#include <string>
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {

}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
    TreeNode* t = expressionStack.top();
    cleanTree(t);
    delete t;
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if (tree != NULL){
        if (tree->right == NULL && tree->left == NULL){
            delete tree;

        }
        cleanTree(tree->right);
        cleanTree(tree->left);
        
    }
   
   
    

}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'|| response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    TreeNode* i = new TreeNode();
    i->value = val;

    if(val != "+" && val != "-" && val != "*" && val != "/"){
        expressionStack.push(i);
    }
    else if (val.length()>=2 && val[0] == '-'){
        expressionStack.push(i);
    }
    else if (val == "+" || (val.length() < 2 && val == "-" )|| val == "*"|| val == "/"){
        TreeNode* c1 = expressionStack.top();
        expressionStack.pop();
        TreeNode* c2 = expressionStack.top();
        expressionStack.pop();
        i->right = c1;
        i->left = c2;
        expressionStack.push(i);
    }

}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format

    if (expressionStack.empty()==false){
    
        if (tree != NULL){
            cout << tree->value << " ";
            printPrefix(tree->left);
            printPrefix(tree->right);
        }


    }


}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
    if (expressionStack.empty()==false){
        if (tree != NULL){
            if (tree->value == "+" ||( tree->value.length() < 2 && tree->value == "-") || tree->value == "*"|| tree->value == "/"){
                cout<< "(";
            }


            printInfix(tree->left);
            cout << tree->value << " ";
            printInfix(tree->right);
    
            if (tree->value == "+" || (tree->value.length() < 2 && tree->value == "-" )|| tree->value == "*"|| tree->value == "/"){
                cout<<  ")";
            }


        }
        
     
    }


}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
   
    if (expressionStack.empty()==false){
        if (tree != NULL){
            printPostfix(tree->left);
            printPostfix(tree->right);
            cout << tree->value << " ";
        }
      

   }

}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result


    if (tree != NULL){
        if (tree->right == NULL && tree->left == NULL){
            return stoi(tree->value);

        }
        
        if (tree->value == "+"){
            return calculate(tree->left) + calculate(tree->right);
            
        }
    
        if (tree->value.length() < 2 && tree->value == "-"){
            return calculate(tree->left) - calculate(tree->right);
            
        }
  
    
        if (tree->value == "*"){
            return calculate(tree->left) * calculate(tree->right);
            
        }   


        if (tree->value == "/"){
            return calculate(tree->left) / calculate(tree->right);
        }
        
        
    }
    
    return 0;
     
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
    TreeNode* n = expressionStack.top();
    return calculate(n);
    delete n;
    
}