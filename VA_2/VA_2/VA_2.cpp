#include "Stack.h"
#include "Queue.h"
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");

	int n_first; int n_second;

	//ввод первого стека
	do { cout << "Введите размер стека 1: "; cin >> n_first; } while (n_first < 0 || n_first > 100);
	Stack S_first(n_first);
	while (S_first.Full() != -1 && n_first != 0) {
		cout << "Введите элемент: ";
		int v; cin >> v;
		S_first.Push(v);
	}

	//ввод второго стека
	do { cout << "Введите размер стека 2: "; cin >> n_second; } while (n_second < 0 || n_second > 100);
	Stack S_second(n_second);
	while (S_second.Full() != -1 && n_second != 0) {
		cout << "Введите элемент: ";
		int v; cin >> v;
		S_second.Push(v);
	}

	//определение размера для 3 стека
	int n_third = S_first.Size() * S_second.Size();
	Stack S_third(n_third); int Count = 0;

	//создаем очередь
	Queue Q(n_third * 2);
	cout << "Введите номера элементов в массиве попарно,которые нужно сложить." << endl;
	cout << "Пример: (эл.1 стека, эл.2стека). Элементы долны быть больше 0." << endl;

	for (int i = 0; i < Q.Size(); i++)
		Q.Push();
	
	int Index_SF, Index_SS;
	Stack add_f(n_first); int SizeF = S_first.Size() ;
	Stack add_s(n_second); int SizeS = S_second.Size();

	//алгоритм создания 3 стека
	for (int i = 0; i < n_third; i++) {
		int fl_1 = 0, fl_2 = 0;

		if ((Q.Front() - 1) < S_first.Size() && Q.Front() > 0) {
			Index_SF = Q.Pop() ; fl_1 = 1;
		}
		else Q.Pop();
		
		if ((Q.Front() - 1) < S_second.Size() && Q.Front() > 0) {
			Index_SS = Q.Pop(); fl_2 = 1;
		}
		else Q.Pop(); 

		if (fl_1 == 1 && fl_2 == 1) {
			int ElementF, ElementS;
			
			//SF
			for (int i = 0; i < SizeF; i++) {
				if (i == Index_SF - 1) {
					ElementF = S_first.Back(); 
				}
				else add_f.Push(S_first.Pop());
			}
			for (int i = 0; i <= add_f.Size(); i++) S_first.Push(add_f.Pop());

			// SS
			for (int i = 0; i < SizeS; i++) {
				if (i == Index_SS - 1) {
					ElementS = S_second.Back();
				}
				else add_s.Push(S_second.Pop());
			}
			for (int i = 0; i <= add_s.Size(); i++) S_second.Push(add_s.Pop());

			S_third.Push(ElementF + ElementS); Count++;
		}

		else cout << "Не правильно введенная пара индексов. " << endl;
	}

	//вывод 3 стека
	cout << "3 стек: " << endl;
	for (int i = 0; i < Count; i++) cout << S_third.Pop() << " ";
	cout << endl;
	

}
