#pragma once
#include "Node.h"
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class BinaryTree
{
public:
	Node* root;
	BinaryTree();

	void insert(int);
	void preOrderTraverse();
	Node* parse(string);

private:
	void preOrderRec(Node*);
	string normalize(string);
	int findIndex(string, int, int);
	Node* parseRec(string, int, int);
};

