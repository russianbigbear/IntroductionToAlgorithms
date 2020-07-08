#include "Tree.h"

int main(void)
{
	setlocale(LC_ALL, "rus");
	do {

		fflush(stdin);
		system("cls");

		Tree* T = new Tree();
		int count, value;
		cout << "������� ���������� ���������: ";
		do {
			cin >> count;
			if (count < 1) cout << "������! ������ �����: ";
		} while (count < 1);
		fflush(stdin);

		cout << "���� ���������: " << endl;
		for (int i = 0; i < count; i++) {
			cin >> value;
			if (!(T->push(T->getRoot(), value))) {
				cout << "������ ����������" << endl;
				i--;
			}
		}

		cout << "���� ������: " << endl;
		T->display(T->getRoot(), 0);

		cout << "���������� ������� � ������: " << T->calculate_leafs(T->getRoot())<< "." << endl;

		cout << "��������� ������? �� - ESC, ��� - ����� �������" << endl;
	} while (_getch() != 27);
	return 0;

}