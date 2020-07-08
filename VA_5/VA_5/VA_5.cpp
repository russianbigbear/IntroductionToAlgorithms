#include "WList.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	int ListCount;
	List *Main = new List();
	
	do {
		cout << "������� ����� ���������: "; cin >> ListCount;
	} while (ListCount <= 0);

	for (int i = 0; i < ListCount; i++) {
		int num;  cin >> num;
		if (i == 0) Main->HeadNum(num);
		else Main->Add(num);
	}
	cout << "�������� ������: " << endl; Main->Show(ListCount);

	int choise;
	do
	{
		cout << "��� ������������� ������?" << endl;
		cout << "������� '1', ���� �� �����������."<< endl;
		cout << "������� '2', ���� �� ��������."<< endl;
		cin >> choise;
	} while (choise != 1 && choise != 2 );

	if (choise == 1) {
		Main->SortUp();
		cout << "��������������� �� ����������� ������: " << endl;  Main->Show(ListCount);
	}
	else {
		Main->SortDown();
		cout << "��������������� �� �������� ������: " << endl; Main->Show(ListCount);
	}

	int a, b;
	do
	{
		cout << "������� ����� ������� ��������� A: "; cin >> a;
	} while (a <= 0 || a > ListCount);
	do
	{
		cout << "������� ������ ������� ��������� B: "; cin >> b;
	} while (b <= 0 || b > ListCount);
	ListCount = Main->DeleteAB(a, b, ListCount);

	Main->Show(ListCount);
}