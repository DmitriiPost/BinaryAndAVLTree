#include <iostream>
#include "BinaryTree.h"
#include "NodeAVL.h"
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
	cout << "Симметричный обход: ";
	string binTreeStr = binTree.inOrderTravers();
	cout << binTreeStr;
	cout << "\n";
	int firstVal = 0;
	int index = 0;
	bool isNegative = false;
	if (binTreeStr[index] == '-') {
		isNegative = true;
		index++; // skip minus
	}

	while (index < binTreeStr.size() && isdigit(binTreeStr[index]))
	{
		firstVal = firstVal * 10 + (binTreeStr[index] - '0');
		index++;
	}
	if (isNegative) {
		firstVal = -firstVal; // Применяем знак минус, если он был
	}
	NodeAVL avlTree(firstVal);
	for (int i = index + 1; i < binTreeStr.size(); i++)
	{
		if (binTreeStr[i] == ' ')
		{
			continue;
		}
		int val = 0;
		bool isNegative = false;
		if (binTreeStr[i] == '-') {
			isNegative = true;
			i++; // skip minus
		}

		while (i < binTreeStr.size() && isdigit(binTreeStr[i]))
		{
			val = val * 10 + (binTreeStr[i] - '0');
			i++;
		}
		if (isNegative) {
			val = -val; // Применяем знак минус, если он был
		}
		avlTree.insert(val);
	}
	cout << "Сформированное АВЛ-дерево; Симметричный обход: ";
	avlTree.inOrderTravers();
	cout << "\n";
	while (true)
	{
		cout << "Выберите опцию:\n1. Вставка элемента\n2. Удаление элемента\n3. Поиск элемента\n4. Обходы дерева\n5. Выход из программы\n";
		int key = 0, optionTr = 0;
		int choise = 0;
		cin >> choise;
		switch (choise)
		{
		case 1:
			system("cls");
			cout << "Введите элемент, который хотите вставить: ";
			cin >> key;
			avlTree.insert(key);
			cout << "Дерево после операции: ";
			avlTree.inOrderTravers();
			break;
		case 2:
			system("cls");
			cout << "Введите элемент, который хотите удалить: ";
			cin >> key;
			avlTree.remove(key);
			cout << "Дерево после операции: ";
			avlTree.inOrderTravers();
			break;
		case 3:
			system("cls");
			cout << "Введите элемент, который хотите найти: ";
			cin >> key;
			avlTree.find(key);
			break;
		case 4:
			system("cls");
			cout << "1. Прямой\n2. Симметричный\n3. Обратный\n4. В ширину\n";
			cin >> optionTr;
			switch (optionTr)
			{
			case 1:
				cout << "Прямой обход: ";
				avlTree.preOrderTravers();
				break;
			case 2:
				cout << "Симметничный обход: ";
				avlTree.inOrderTravers();
				break;
			case 3:
				cout << "Обратный обход: ";
				avlTree.postOrderTravers();
				break;
			case 4:
				cout << "Обход в ширину: ";
				avlTree.levelOrderTravers();
				break;
			default:
				cout << "Нет такой опции\n";
				break;
			}
			break;
		case 5:
			cout << "Выход из программы...";
			exit(0);
		default:
			cout << "Нет такой опции, попробуйте еще!\n";
			break;
		}
	}
}
