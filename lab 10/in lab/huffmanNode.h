//huffmanNode.h
//Lab 10: In-Lab
//Name: Gizella Wade
//ID: grw7b


#ifndef HUFFMANNODE_H //change to heap from binary heap
#define HUFFMANNODE_H

#include <iostream>
#include <string>
using namespace std;


class huffmanNode {
public:
	huffmanNode();
	huffmanNode(int freq, char c);
	~huffmanNode();
    int frequency;
    char c;
    string prefix;
    huffmanNode* left, *right;
};

#endif