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
	int Height; // высота элемента
};

typedef struct Item *Root;  // указатель на корень

/* Класс Tree */
class Tree {
private:
	int _count_likes_keys = 0;
public:
	int tree_height(Root);
	int tree_fixheight(int, int);
	Root srl(Root &);
	Root srr(Root &);
	Root drl(Root &);
	Root drr(Root &);
	void push(Root &, int);
	void display(Root, int);
	bool find(Root &, int);
	int likes_keys(Root p, Root p2);

};

/*высота */
int Tree::tree_height(Root r) {
	if (r == NULL) return -1;
	else return r->Height;
}

/*вычисление высоты из значений*/
int Tree::tree_fixheight(int value_left, int value_right) {
	return ((value_left > value_right) ? value_left : value_right);
}

/*малый правый поворот*/
Root Tree::srl(Root &q) {
	Root p;
	p = q->Left;
	q->Left = p->Right;
	p->Right = q;

	q->Height = tree_fixheight(tree_height(q->Left), tree_height(q->Right)) + 1;
	p->Height = tree_fixheight(tree_height(p->Left), q->Height) + 1;
	return p;
}

/*малый левый поворот*/
Root Tree::srr(Root &p) {
	Root q;
	q = p->Right;
	p->Right = q->Left;
	q->Left = p;

	p->Height = tree_fixheight(tree_height(p->Left), tree_height(p->Right)) + 1;
	q->Height = tree_fixheight(p->Height, tree_height(q->Right)) + 1;
	return q;
}

/*большой правый поворот*/
Root Tree::drl(Root &q) {
	q->Left = srr(q->Left);
	return srl(q);
}

/*большой левый поворот*/
Root Tree::drr(Root &p) {
	p->Right = srl(p->Right);
	return srr(p);
}

/*добавление элемента в дерево*/
void Tree::push(Root &r, int x) {
	if (r == NULL) {
		r = new Item;
		r->Data = x;
		r->Left = NULL;
		r->Right = NULL;
		r->Height = 0;
		if (r == NULL) cout << "Нельзя создать дерево\n" << endl;
	}
	else {
		if (x < r->Data) {
			push(r->Left, x);
			if ((tree_height(r->Left) - tree_height(r->Right))  == 2) 
				if (x < r->Left->Data) r = srl(r);
				else r = drl(r);
		}
		else
			if (x > r->Data) {
				push(r->Right, x);
				if ((tree_height(r->Right) - tree_height(r->Left)) == 2) 
					if (x > r->Right->Data) r = srr(r);
					else r = drr(r);
			}
			else cout << "Элемент существует." << endl;
	}
	int m = tree_height(r->Left);
	int n = tree_height(r->Right);
	int d = tree_fixheight(m, n);
	r->Height = d + 1;
}

void Tree::display(Root r, int l) {
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

/*поиск элемента в дереве*/
bool Tree::find(Root &r, int x)
{
	if (r == NULL)
		return false; 
	//cout << "Простите, но такого элемента нет\n" << endl;
	else
		if (x < r->Data)
			find(r->Left, x);
		else
			if (x > r->Data)
				find(r->Right, x);
			else
				return true;
	//cout << "Элемент, который вы искали есть в дереве!\n" << endl;	
}

/*Обход и подсчет количества схожих элементов с другим деревом*/
int Tree::likes_keys(Root p, Root p2) {
	if (p != NULL) {
		if (find(p2, p->Data)) _count_likes_keys++;
		likes_keys(p->Left, p2);
		likes_keys(p->Right, p2);
	}
	else return _count_likes_keys;
}