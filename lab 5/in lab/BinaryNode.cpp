#include "BinaryNode.h"
#include <string>
using namespace std;

BinaryNode::BinaryNode() {
    value = "?";
    left = NULL;
    right = NULL;
}
BinaryNode::BinaryNode(string val,BinaryNode* rt, BinaryNode* lt){
	value = val;
	right = rt;
	left = lt;


}
BinaryNode::~BinaryNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}