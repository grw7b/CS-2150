//AVLTree.cpp
#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
    count = 0;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
    count = 0;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    root = insert(root,x);
}

AVLNode* AVLTree::insert(AVLNode*& r,const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    if (r == NULL){
        count++;
        r = new AVLNode(x, NULL, NULL, 0);
       
    }

    else if (r->value < x){
        insert(r->right, x);
        //balance(r);
    }

    else if (r->value > x){
        insert(r->left, x);
        //balance(r);
    }

    r->height = 1 + max(height(r->left), height(r->right));
    balance(r);
    
    return r;
   
}




// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    string m = "";
    return pathTo(root,m,x);
    
}

string AVLTree::pathTo(AVLNode* r, string rslt, const string& x) const{

    if (r != NULL && find(r,x)==true) {
        if (r->value == x){
            rslt += r->value;
            rslt += " ";
            return rslt;
        }
        else if (r->value < x){
            rslt += r->value;
            rslt += " ";
            //cout << rslt << endl;
            return pathTo(r->right,rslt, x);
        }
    
        else if (r->value > x){
            rslt+= r->value;
            rslt += " ";
            //cout << rslt << endl;
            return pathTo(r->left,rslt,x);
        }

    }

    return rslt;
}




// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    return find(root,x);
}

bool AVLTree::find(AVLNode* r,const string& x) const{
    
    if(r == NULL){
        return false;
    }
    else if (r->value < x){
        return find(r->right, x);
    }
    else if (r->value > x){
        return find(r->left,x);
    }
    
    return true;

}




// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
    return count;
}





// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE

    if (n == NULL){
        return;
    }


    int bal = height(n->right) - height(n->left); 

    if (bal > 1) { //balance factor of node is 2 rotate left

        if (height(n->right->right) - height(n->right->left)  < 0) { //balance factor of right child is negative:
            //rotate right on the right child
           
            n->right = rotateRight(n->right);
            n = rotateLeft(n);
        }
        
        else{
            n = rotateLeft(n);
        }
   
   }
        
    else if  (bal < -1) { //balance factor of node is -2 rotate right

        if (height(n->left->right) - height(n->left->left)  > 0){
            //rotate left on the left child
            n->left = rotateLeft(n->left);
            n = rotateRight(n);
        }
        
        else{
        //rotate right on node
        n = rotateRight(n);

        }
    }
}



// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* s = n->right;
    n->right = s->left;
    s->left = n;
    
    
    n->height = max(height(n->left), height(n->right)) + 1;
    s->height = max(height(s->left), height(s->right)) + 1;

    return s;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* s = n->left;
    n->left = s->right;
    s->right = n;
   
    
    n->height = max(height(n->left),height(n->right)) + 1;
    s->height = max(height(s->left), height(s->right)) + 1;

    return s;

}





// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    count--;
    root = remove(root, x);
}




// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        count++;
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}