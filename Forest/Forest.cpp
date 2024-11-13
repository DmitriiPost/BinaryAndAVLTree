#include <iostream>
#include "BinaryTree.h"
#include <fstream>
#include <string>

using namespace std;

string readFromFile(string path)
{
	ifstream database(path);
	if (!database.is_open())
	{
		cout << "Ошибка открытия файла!\n";
		return " ";
	}
	string res;
	if (getline(database, res))
	{
		database.close();
		return res;
	}
	else
	{
		cout << "В файле нет данных!\n";
		database.close();
		return " ";
	}
}

int main()
{
	setlocale(0, "");
	BinaryTree binTree;
	string path = "C:\\Users\\mitya\\source\\repos\\Forest\\input.txt";
	string forTree = readFromFile(path);
	if (forTree == " ")
	{
		return 0;
	}
	Node* node = binTree.parse(forTree);
	binTree.root = node;
	cout << "Прямой обход: ";
	binTree.preOrderTraverse();
	cout << "\n";
}
