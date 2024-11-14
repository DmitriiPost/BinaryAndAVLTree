#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	root = nullptr;
}

void BinaryTree::insert(int val)
{
	Node* newNode = new Node(val);
	if (root == nullptr)
	{
		root = newNode;
		return;
	}
	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* curr = q.front();
		q.pop();

		if (curr->left == nullptr)
		{
			curr->left = newNode;
			return;
		}
		else
		{
			q.push(curr->left);
		}

		if (curr->right == nullptr)
		{
			curr->right = newNode;
			return;
		}
		else
		{
			q.push(curr->right);
		}
	}
}

string BinaryTree::inOrderTravers()
{
	return inOrderRec(root);
}

string BinaryTree::inOrderRec(Node* node)
{
	string res = "";
	if (node)
	{
		res += inOrderRec(node->left);
		res += to_string(node->value);
		res += " ";
		res += inOrderRec(node->right);
	}
	return res;
}

Node* BinaryTree::parse(string s)
{
	s = normalize(s);
	return parseRec(s, 0, s.size() - 1);
}

Node* BinaryTree::parseRec(string s, int start, int end)
{
	if (start >  end)
	{
		return nullptr;
	}
	int val = 0;
	bool isNegative = false;
	if (s[start] == '-') {
		isNegative = true;
		start++; // skip minus
	}

	while (start < s.size() && isdigit(s[start]))
	{
		val = val * 10 + (s[start] - '0');
		start++;
	}
	if (isNegative) {
		val = -val; // Применяем знак минус, если он был
	}
	Node* node = new Node(val);
	int index = -1;
	if (start <= end && s[start] == '(')
	{
		index = findIndex(s, start, end);
	}
	if (index != -1)
	{
		node->left = parseRec(s, start + 1, index - 1);
		node->right = parseRec(s, index + 2, end - 1);
	}
	return node;
}

string BinaryTree::normalize(string str)
{
	string res = "";
	for (int i = 1; i < str.size() - 1; i++)
	{
		if (str[i] != ' ')
		{
			res += str[i];
		}
	}
	return res;
}

int BinaryTree::findIndex(string str, int start, int end)
{
	if (start > end)
	{
		return -1;
	}
	stack<char> s;
	for (int i = start; i <= end; i++)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (s.top() == '(')
			{
				s.pop();
				if (s.empty())
				{
					return i;
				}
			}
		}
	}
	return -1; // not found
}

/*Node* BinaryTree::parseRec(const string& s, unsigned& index)
{
	while (s[index] == ' ' && index < s.size())
	{
		index++; // ignore spaces
	}
	if (index >= s.size() || s[index] == ')')
	{
		cout << "Error with index...";
		return nullptr;
	}
	int val = 0;
	bool isNegative = false;
	if (s[index] == '-') {
		isNegative = true;
		index++; // Пропускаем знак минус
	}

	while (index < s.size() && isdigit(s[index]))
	{
		val = val * 10 + (s[index] - '0');
		index++;
	}

	while(s[index] == ' ' && index < s.size())
	{
		index++; // ignore spaces
	}
	if (isNegative) {
		val = -val; // Применяем знак минус, если он был
	}
	Node* node = new Node(val);
	if (index < s.size() && s[index] == '(')
	{
		index++; // skip (
		node->left = parseRec(s, index);
		if (index < s.size() && s[index] == ')')
		{
			index++; // skip )
		}
	}
	if (index < s.size() && s[index] == '(')
	{
		index++; // skip (
		node->right = parseRec(s, index);
		if (index < s.size() && s[index] == ')')
		{
			index++; // skip )
		}
	}
	return node;
}*/