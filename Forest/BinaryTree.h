#pragma once
#include "Node.h"
#include <queue>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

class BinaryTree
{
public:
	Node* root;
	BinaryTree();

	void insert(int);
	string inOrderTravers();
	Node* parse(string);

private:
	string inOrderRec(Node*);
	string normalize(string);
	int findIndex(string, int, int);
	Node* parseRec(string, int, int);
};

