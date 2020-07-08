#pragma once
#include <iostream>
#include <conio.h>
#include <locale.h>

using namespace std;

/*
Структура Item представляет собой вершину(узел) бинарного дерева.
Data - поле данных, Left - указатель на левого потомка,
Right - указатель на правого потомка.
*/
struct Item {
	int Data; // поле данных
	Item* Left; // указатель на левого потомка
	Item* Right; // указатель на правого потомка
};
/*
Класс Tree
*/
class Tree {
	Item* Root; // указатель на корень
	int count_leafs = 0;
public:
	bool push(Item* r, int x); //добавление элемента в дерево
	void display(Item* r, int l); //вывод красивого дерева
	Item* getRoot();
	Item* remove(Item* r, int x);
	int calculate_leafs(Item* r);
	Tree(void); // конструктор
	~Tree(void); // деструктор
};
/*конструктор*/
Tree::Tree(void)
{
	Root = new Item();
	Root = NULL;
}
/*деструктор*/
Tree::~Tree(void){}

/* возвращает указатель на корень дерева*/
Item* Tree::getRoot() {
	return Root;
}
/* добавление элемента в дерево*/
bool Tree::push(Item* r, int x) {
	Item *tmp = new Item();
	tmp->Data = x;
	tmp->Left = NULL;
	tmp->Right = NULL;
	if (Root == NULL) {
		Root = tmp;
		return true;
	}
	if (r->Data == x)
		return false;
	if (r->Data < x) {
		if (r->Right)
			push(r->Right, x);
		else
			r->Right = tmp;
	}
	else
		if (r->Left)
			push(r->Left, x);
		else
			r->Left = tmp;
	return true;
}
/* вывод красивого дерева*/
void Tree::display(Item* r, int l) {
	if (r != NULL) {
		display(r->Right, l + 1);
		for (int i = 0; i < l; i++)
			cout << "	";
		cout << r->Data;
		display(r->Left, l + 1);
	}
	else
		cout << endl;
}

/*удаление элемента дерева*/
Item* Tree::remove(Item* r, int x) {
	if (r == NULL)
		return r;
	if (x < r->Data)
		r->Left = remove(r->Left, x);
	else
		if (x > r->Data)
			r->Right = remove(r->Right, x);
		else
			if (r == Root)
			{
				if (Root->Right == NULL)
					Root->Left->Right = r->Right;
				Root = Root->Left;
			}
			else
				if (r->Left != NULL)
				{
					r->Left->Right = r->Right;
					r = r->Left;
				}
				else
					if (r->Right != NULL)
						r = r->Right;
	return r;
}

/*подсчет листьев дерева*/
int Tree::calculate_leafs(Item* r) {
	if (r != NULL) {
		calculate_leafs(r->Left);
		if (r->Left == NULL && r->Right == NULL) count_leafs++;
		calculate_leafs(r->Right);
	}
	else return count_leafs;
}
