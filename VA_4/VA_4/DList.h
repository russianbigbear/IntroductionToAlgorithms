#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#define MySize 10
using namespace std;

struct D_List
{
	int data; //информационное поле
	D_List *Next; //указатель на следующий элемент
	D_List *Prev; //указатель на предыдущий элемент
};

D_List *Head;
D_List *Current;

/*создание упор€доченного по возрастанию списка*/
void Make_D_List(int n, D_List** Head, D_List* Prev)
{
	(*Head) = new D_List();
	//выдел€ем пам€ть под новый элемент
	(*Head)->data = n;
	(*Head)->Prev = Prev;
	(*Head)->Next = NULL;//обнуление адресного пол€
}

/*печать списка*/
void Print_D_List(D_List* Head)
{
	if (Head != NULL)
	{
		cout << Head->data << " ";
		Print_D_List(Head->Next);
		//переход к следующему элементу
	}
	else
	{
		cout << endl;
	}
}

/*вставка на определЄнную позицию*/
D_List* Insert_Item_D_List(D_List* Head,
	int Number, int DataItem)
{
	Number--;
	D_List *NewItem = new(D_List);
	NewItem->data = DataItem;
	NewItem->Prev = NULL;
	NewItem->Next = NULL;
	if (Head == NULL)
	{//список пуст
		Head = NewItem;
	}
	else
	{//список не пуст
		D_List *Current = Head;
		for (int i = 1; i < Number && Current->Next != NULL; i++)
			Current = Current->Next;
		if (Number == 0)
		{
			//вставл€ем новый элемент на первое место
			NewItem->Next = Head;
			Head = NewItem;
		}
		else
		{//вставл€ем новый элемент на непервое место
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

/*удаление элемента с заданным номером из двунаправленного списка*/
D_List* Delete_Item_D_List(D_List* Head,
	int Number) {
	D_List *ptr;//вспомогательный указатель
	D_List *Current = Head;
	for (int i = 1; i < Number && Current != NULL; i++)
		Current = Current->Next;
	if (Current != NULL) {//проверка на пустоту
		if (Current->Prev == NULL) {//удал€ем первый элемент
			Head = Head->Next;
			delete(Current);
			Head->Prev = NULL;
			Current = Head;
		}
		else {//удал€ем непервый элемент
			if (Current->Next == NULL) {
				//удал€ем последний элемент
				Current->Prev->Next = NULL;
				delete(Current);
				Current = Head;
			}
			else {//удал€ем непервый и непоследний элемент
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

/*удаление списка*/
void Delete_D_List(D_List* Head) {
	if (Head != NULL) {
		Delete_D_List(Head->Next);
		delete Head;
	}
}

/*номер места дл€ вставки*/
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

/*сортировка по возрастанию*/
D_List* Sort_Ascending(D_List *Head, int mas[], int size)
{
	for (int i = 1; i < size; i++)
		Head = Insert_Item_D_List(Head, ReturnUp(Head, mas[i]), mas[i]);
	
	return Head;
}

/*сливаем два списка*/
D_List* Add_D_List(D_List *first, D_List *second) {
	D_List *third = first;
	D_List *Current = first;

	while (Current->Next != NULL)
		Current = Current->Next;

	Current->Next = second;
	second->Prev = Current;

	return third;
}

