#include "WList.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");
	int ListCount;
	List *Main = new List();
	
	do {
		cout << "Введите число элементов: "; cin >> ListCount;
	} while (ListCount <= 0);

	for (int i = 0; i < ListCount; i++) {
		int num;  cin >> num;
		if (i == 0) Main->HeadNum(num);
		else Main->Add(num);
	}
	cout << "Введеный список: " << endl; Main->Show(ListCount);

	int choise;
	do
	{
		cout << "Как отсоритровать список?" << endl;
		cout << "Введите '1', если по возрастанию."<< endl;
		cout << "Введите '2', если по убыванию."<< endl;
		cin >> choise;
	} while (choise != 1 && choise != 2 );

	if (choise == 1) {
		Main->SortUp();
		cout << "Отсортированный по возрастанию список: " << endl;  Main->Show(ListCount);
	}
	else {
		Main->SortDown();
		cout << "Отсортированный по убыванию список: " << endl; Main->Show(ListCount);
	}

	int a, b;
	do
	{
		cout << "Введите левую границу интервала A: "; cin >> a;
	} while (a <= 0 || a > ListCount);
	do
	{
		cout << "Введите правую границу интервала B: "; cin >> b;
	} while (b <= 0 || b > ListCount);
	ListCount = Main->DeleteAB(a, b, ListCount);

	Main->Show(ListCount);
}