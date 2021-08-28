//AVLNode.cpp
#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
    value = "?";
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::AVLNode(string val, AVLNode* rt, AVLNode* lt, int h) {
    value = val;
    lt = NULL;
    rt = NULL;
    height = h;
}

AVLNode::~AVLNode() {
    delete left;
    delete right;
}
