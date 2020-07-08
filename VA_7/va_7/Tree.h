#pragma once
#include <iostream>
#include <conio.h>
#include <locale.h>

using namespace std;

/*
��������� Item ������������ ����� �������(����) ��������� ������.
Data - ���� ������, Left - ��������� �� ������ �������,
Right - ��������� �� ������� �������.
*/
struct Item {
	int Data; // ���� ������
	Item* Left; // ��������� �� ������ �������
	Item* Right; // ��������� �� ������� �������
};
/*
����� Tree
*/
class Tree {
	Item* Root; // ��������� �� ������
	int count_leafs = 0;
public:
	bool push(Item* r, int x); //���������� �������� � ������
	void display(Item* r, int l); //����� ��������� ������
	Item* getRoot();
	Item* remove(Item* r, int x);
	int calculate_leafs(Item* r);
	Tree(void); // �����������
	~Tree(void); // ����������
};
/*�����������*/
Tree::Tree(void)
{
	Root = new Item();
	Root = NULL;
}
/*����������*/
Tree::~Tree(void){}

/* ���������� ��������� �� ������ ������*/
Item* Tree::getRoot() {
	return Root;
}
/* ���������� �������� � ������*/
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
/* ����� ��������� ������*/
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

/*�������� �������� ������*/
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

/*������� ������� ������*/
int Tree::calculate_leafs(Item* r) {
	if (r != NULL) {
		calculate_leafs(r->Left);
		if (r->Left == NULL && r->Right == NULL) count_leafs++;
		calculate_leafs(r->Right);
	}
	else return count_leafs;
}
