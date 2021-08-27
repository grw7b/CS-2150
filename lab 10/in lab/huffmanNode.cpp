//huffmanNode.cpp
//Lab 10: In-Lab
//Name: Gizella Wade
//ID: grw7b

#include <iostream>
#include "huffmanNode.h"
using namespace std;

huffmanNode::huffmanNode(){
	frequency = 1;
	c = '\0';
	left = NULL;
	right = NULL;
	prefix = "";

}

huffmanNode::huffmanNode(int freq, char character){
	frequency = freq;
	c = character;
	left = NULL;
	right = NULL;
	prefix = "";

}


huffmanNode::~huffmanNode(){
	delete right;
	delete left;

}