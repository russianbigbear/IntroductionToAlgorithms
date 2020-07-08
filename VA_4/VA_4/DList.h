#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#define MySize 10
using namespace std;

struct D_List
{
	int data; //�������������� ����
	D_List *Next; //��������� �� ��������� �������
	D_List *Prev; //��������� �� ���������� �������
};

D_List *Head;
D_List *Current;

/*�������� �������������� �� ����������� ������*/
void Make_D_List(int n, D_List** Head, D_List* Prev)
{
	(*Head) = new D_List();
	//�������� ������ ��� ����� �������
	(*Head)->data = n;
	(*Head)->Prev = Prev;
	(*Head)->Next = NULL;//��������� ��������� ����
}

/*������ ������*/
void Print_D_List(D_List* Head)
{
	if (Head != NULL)
	{
		cout << Head->data << " ";
		Print_D_List(Head->Next);
		//������� � ���������� ��������
	}
	else
	{
		cout << endl;
	}
}

/*������� �� ����������� �������*/
D_List* Insert_Item_D_List(D_List* Head,
	int Number, int DataItem)
{
	Number--;
	D_List *NewItem = new(D_List);
	NewItem->data = DataItem;
	NewItem->Prev = NULL;
	NewItem->Next = NULL;
	if (Head == NULL)
	{//������ ����
		Head = NewItem;
	}
	else
	{//������ �� ����
		D_List *Current = Head;
		for (int i = 1; i < Number && Current->Next != NULL; i++)
			Current = Current->Next;
		if (Number == 0)
		{
			//��������� ����� ������� �� ������ �����
			NewItem->Next = Head;
			Head = NewItem;
		}
		else
		{//��������� ����� ������� �� �������� �����
			if (Current->Next != NULL)
				Current->Next->Prev = NewItem;
			NewItem->Next = Current->Next;
			Current->Next = NewItem;
			NewItem->Prev = Current;
			Current = NewItem;
		}
	}
	return Head;
}

/*�������� �������� � �������� ������� �� ���������������� ������*/
D_List* Delete_Item_D_List(D_List* Head,
	int Number) {
	D_List *ptr;//��������������� ���������
	D_List *Current = Head;
	for (int i = 1; i < Number && Current != NULL; i++)
		Current = Current->Next;
	if (Current != NULL) {//�������� �� �������
		if (Current->Prev == NULL) {//������� ������ �������
			Head = Head->Next;
			delete(Current);
			Head->Prev = NULL;
			Current = Head;
		}
		else {//������� �������� �������
			if (Current->Next == NULL) {
				//������� ��������� �������
				Current->Prev->Next = NULL;
				delete(Current);
				Current = Head;
			}
			else {//������� �������� � ����������� �������
				ptr = Current->Next;
				Current->Prev->Next = Current->Next;
				Current->Next->Prev = Current->Prev;
				delete(Current);
				Current = ptr;
			}
		}
	}
	return Head;
}

/*�������� ������*/
void Delete_D_List(D_List* Head) {
	if (Head != NULL) {
		Delete_D_List(Head->Next);
		delete Head;
	}
}

/*����� ����� ��� �������*/
int ReturnUp(D_List *Head, int key)
{
	D_List *Current = Head;
	int place = 1;
	while (Current != NULL)
	{
		if (key > Current->data) place++;
		Current = Current->Next;
	}
	return place;
}

/*���������� �� �����������*/
D_List* Sort_Ascending(D_List *Head, int mas[], int size)
{
	for (int i = 1; i < size; i++)
		Head = Insert_Item_D_List(Head, ReturnUp(Head, mas[i]), mas[i]);
	
	return Head;
}

/*������� ��� ������*/
D_List* Add_D_List(D_List *first, D_List *second) {
	D_List *third = first;
	D_List *Current = first;

	while (Current->Next != NULL)
		Current = Current->Next;

	Current->Next = second;
	second->Prev = Current;

	return third;
}

