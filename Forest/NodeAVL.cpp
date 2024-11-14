#include "NodeAVL.h"

NodeAVL::NodeAVL(int k)
{
	value = k;
	height = 1;
	left = nullptr;
	right = nullptr;
}

int NodeAVL::getHeight(NodeAVL* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return node->height;
}

void NodeAVL::fixHeight()
{
	int hl = getHeight(left);
	int hr = getHeight(right);
	height = (hl > hr ? hl : hr);
}

NodeAVL* NodeAVL::rotateRight(NodeAVL* node)
{
	NodeAVL* q = node->left;
	node->left = q->right;
	q->right = node;
	node->fixHeight();
	q->fixHeight();
	return q;
}

NodeAVL* NodeAVL::rotateLeft(NodeAVL* node)
{
	NodeAVL* p = node->right;
	node->right = p->left;
	p->left = node;
	node->fixHeight();
	p->fixHeight();
	return p;
}

int NodeAVL::getBalance()
{
	return getHeight(left) - getHeight(right);
}

NodeAVL* NodeAVL::insert(int key)
{
	if (key < value)
	{
		if (!left)
		{
			left = new NodeAVL(key);
		}
		else
		{
			left = left->insert(key);
		}
	}
	else if (key > value)
	{
		if (!right)
		{
			right = new NodeAVL(key);
		}
		else
		{
			right = right->insert(key);
		}
	}
	else
	{
		cout << "“акой элемент уже есть в дереве\n";
		return this;
	}
	return this->balance();
}

NodeAVL* NodeAVL::balance()
{
	this->fixHeight();
	int difference = getBalance();
	if (difference == 2)
	{
		if (right->getBalance() < 0)
		{
			right = rotateRight(right);
		}
		return rotateLeft(this);
	}
	else if (difference == -2)
	{
		if (left->getBalance() > 0)
		{
			left = rotateLeft(left);
		}
		return rotateRight(this);
	}
	return this;
}

NodeAVL* NodeAVL::remove(int key)
{
	if (this == nullptr)
	{
		return nullptr;
	}
	if (key < value)
	{
		left = left->remove(key);
	}
	else if (key > value)
	{
		right = right->remove(key);
	}
	else
	{
		if (left == nullptr && right == nullptr)
		{
			return nullptr;
		}
		if (left == nullptr)
		{
			return right;
		}
		if (right == nullptr)
		{
			return left;
		}
		// 2 children
		NodeAVL* minInRight = minValueNode(right);
		this->value = minInRight->value;
		right = right->remove(minInRight->value);
	}
	return balance();
}

NodeAVL* NodeAVL::minValueNode(NodeAVL* node)
{
	NodeAVL* curr = node;
	while (curr->left)
	{
		curr = curr->left;
	}
	return curr;
}

NodeAVL* NodeAVL::find(int key)
{
	if (key == value)
	{
		cout << "Ёлемент найден!\n";
		return this;
	}
	else if (key < value)
	{
		if (left == nullptr)
		{
			cout << "Ёлемент не найден\n";
			return nullptr;
		}
		return left->find(key);
	}
	else
	{
		if (right == nullptr)
		{
			cout << "Ёлемент не найден\n";
			return nullptr;
		}
		return right->find(key);
	}
}

void NodeAVL::preOrderTravers()
{
	stack<NodeAVL*> q;
	q.push(this);
	while (!q.empty())
	{
		NodeAVL* curr = q.top();
		q.pop();
		cout << curr->value << " ";
		if (curr->left)
		{
			q.push(curr->left);
		}
		if (curr->right)
		{
			q.push(curr->right);
		}
	}
}

/*void AvlTree::preOrderRec(NodeAVL* node)
{
	if (node)
	{
		cout << node->value << " ";
		preOrderRec(node->left);
		preOrderRec(node->right);
	}
}*/

void NodeAVL::inOrderTravers()
{
	stack<NodeAVL*> q;
	NodeAVL* curr = this;
	while (curr || !q.empty())
	{
		while (curr)
		{
			q.push(curr);
			curr = curr->left;
		}
		curr = q.top();
		q.pop();
		cout << curr->value << " ";
		curr = curr->right;
	}
}

/*void AvlTree::inOrderRec(NodeAVL* node)
{
	if (node)
	{
		inOrderRec(node->left);
		cout << node->value << " ";
		inOrderRec(node->right);
	}
}*/

void NodeAVL::postOrderTravers()
{
	stack<NodeAVL*> q;
	stack<NodeAVL*> out;
	q.push(this);

	while (!q.empty())
	{
		NodeAVL* curr = q.top();
		q.pop();
		out.push(curr);
		if (curr->left)
		{
			q.push(curr->left);
		}
		if (curr->right)
		{
			q.push(curr->right);
		}
	}

	while (!out.empty())
	{
		NodeAVL* curr = out.top();
		out.pop();
		cout << curr->value << " ";
	}
}

/*void AvlTree::postOrderRec(NodeAVL* node)
{
	if (node)
	{
		postOrderRec(node->left);
		postOrderRec(node->right);
		cout << node->value << " ";
	}
}*/

void NodeAVL::levelOrderTravers()
{
	queue<NodeAVL*> q;
	q.push(this);
	while (!q.empty())
	{
		NodeAVL* node = q.front();
		cout << node->value << " ";
		q.pop();

		if (node->left)
		{
			q.push(node->left);
		}
		if (node->right)
		{
			q.push(node->right);
		}
	}
}