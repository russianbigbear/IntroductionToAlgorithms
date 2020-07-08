#include "Tree.h"

int main(void)
{
	setlocale(LC_ALL, "rus");
	do {

		fflush(stdin);
		system("cls");

		Tree* T = new Tree();
		int count, value;
		cout << "Введите количество элементов: ";
		do {
			cin >> count;
			if (count < 1) cout << "Ошибка! Повтор ввода: ";
		} while (count < 1);
		fflush(stdin);

		cout << "Ввод элементов: " << endl;
		for (int i = 0; i < count; i++) {
			cin >> value;
			if (!(T->push(T->getRoot(), value))) {
				cout << "Ошибка добавления" << endl;
				i--;
			}
		}

		cout << "Наша дерево: " << endl;
		T->display(T->getRoot(), 0);

		cout << "Количество листьев в дереве: " << T->calculate_leafs(T->getRoot())<< "." << endl;

		cout << "Закончить работу? да - ESC, нет - любая клавиша" << endl;
	} while (_getch() != 27);
	return 0;

}