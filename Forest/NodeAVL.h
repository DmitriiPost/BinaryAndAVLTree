#pragma once
#include "NodeAVL.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class NodeAVL
{
public:
	int value;
	int height;
	NodeAVL* left;
	NodeAVL* right;
	NodeAVL(int);
	int getHeight(NodeAVL*);
	NodeAVL* insert(int);
	NodeAVL* remove(int);
	NodeAVL* find(int);
	void preOrderTravers();
	void inOrderTravers();
	void postOrderTravers();
	void levelOrderTravers();
private:
	void fixHeight();
	NodeAVL* rotateRight(NodeAVL*);
	NodeAVL* rotateLeft(NodeAVL*);
	NodeAVL* balance();
	int getBalance();
	NodeAVL* minValueNode(NodeAVL*);;
};

