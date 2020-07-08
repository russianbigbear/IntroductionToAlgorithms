#include <iostream>
#include <stdlib.h>
using namespace std;
#define ignorecin cin.clear(); cin.ignore(cin.rdbuf()->in_avail())
#define clearcin cin.clear(); while(cin.get()!='\n');

struct S_List
{
	int _key;
	char _data[40];
	S_List *_next;
};

void Create_S_List(int number, S_List **Head) {
	if (number > 0) {
		(*Head) = new S_List();
		cout << "¬ведите фамилию абитуриента: "; cin >> (*Head)->_data;
		cout << "¬ведите уникальный цифровой ID: "; cin >> (*Head)->_key;
		(*Head)->_next = NULL;
		Create_S_List(number - 1, &((*Head)->_next));
	}
}


void Print_S_List(S_List *Head) {

	if (Head != NULL)
	{
		cout << Head->_key << " " << Head->_data << endl;
		Print_S_List(Head->_next);
	}
	else cout << endl;
}

int Compare_S_List(S_List *Head_F, S_List *Head_S, S_List **Head_T) {
	int fl_count = 0;
	S_List *Current_T;

	for (S_List *Current_F = Head_F; Current_F != NULL; Current_F = Current_F->_next) {
		for (S_List *Current_S = Head_S; Current_S != NULL; Current_S = Current_S->_next) {
			if (strcmp(Current_F->_data, Current_S->_data) == 0 && (Current_F->_key == Current_S->_key)) {
				if (fl_count == 0) {
					(*Head_T) = new S_List();
					strcpy((*Head_T)->_data, Current_F->_data);
					(*Head_T)->_key = Current_F->_key;
					(*Head_T)->_next = NULL;
					Current_T = *Head_T;
					fl_count++;
				}
				else {
					(*Head_T) = (*Head_T)->_next = new S_List();
					strcpy((*Head_T)->_data, Current_F->_data);
					(*Head_T)->_key = Current_F->_key;
					(*Head_T)->_next = NULL;
				}
			}
		}
	}

	if (fl_count) *Head_T = Current_T;
	
	return fl_count;
}

int Size(S_List *Head) {
	int count = 0;
	while (Head != NULL) {
		count++;
		Head = Head->_next;
	}
	return count;
}
void Delete_S_List(S_List *Head) {
	if (Head != NULL) {
		Delete_S_List(Head->_next);
		delete Head;
	}
}