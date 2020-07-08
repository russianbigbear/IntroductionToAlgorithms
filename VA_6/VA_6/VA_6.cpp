#include "Tree.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	do {

		fflush(stdin);
		system("cls");

		Tree T_First; Root Root_F = NULL;
		Tree T_Second; Root Root_S = NULL;
		int countF, countS;
		int value;

		//Добавление и вывод первого дерева
		cout << "Введите количество элементов первого АВЛ - дерева: ";
		do {
			cin >> countF;
			if (countF < 1) cout << "Ошибка! Повтор ввода: ";
		} while (countF < 1);

		fflush(stdin);

		cout << "Ввод элементов: " << endl;
		for (int i = 0; i < countF; i++){
			cin >> value;
			if( !(T_First.find(Root_F, value)) )
				T_First.push(Root_F, value);
			else { i--;  cout << "Элемент существует." << endl; }
		}
		cout << "Первое дерево:" << endl;
		T_First.display(Root_F,0); cout << endl;

		//Добавление и вывод второго дерева
		cout << "Введите количество элементов второго АВЛ - дерева: ";
		do {
			cin >> countS;
			if (countS < 1) cout << "Ошибка! Повтор ввода: ";
		} while (countS < 1);

		fflush(stdin);

		cout << "Ввод элементов: " << endl;
		for (int i = 0; i < countS; i++) {
			cin >> value;
			if (!(T_Second.find(Root_S, value)))
				T_Second.push(Root_S, value);
			else { i--;  cout << "Элемент существует." << endl; };
		}
		cout << "Второе дерево:" << endl;
		T_Second.display(Root_S, 0); cout << endl;

		/*находим процент ключей первого дерева,
		принадлежащих второму дереву*/
		double likes_keys = T_First.likes_keys(Root_F, Root_S),
			double_countF = countF;
		cout << (likes_keys/ double_countF * 100) << "% ключей первого АВЛ дерева, принадлежат второму АВЛ дереву" << endl;
		
		cout << "Закончить работу? да - ESC, нет - любая клавиша" << endl;
	} while (_getch() != 27);
	return 0;
}