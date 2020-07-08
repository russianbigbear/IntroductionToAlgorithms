#include <iostream>
#include <locale.h>
using namespace std;

int main() {
	
	//размер матрицы
	int n, m; 
	
	setlocale(LC_ALL, "rus");

	//ввод размеров матрицы
	do {
		cout << "Введите размеры матрицы от 1 до 10." << endl;
		cout << "N: "; cin >> n;
		cout << "M: "; cin >> m;
	} while ((n <= 0 || n >= 11) || (m <= 0 || m >= 11));

	//динамическое выделение памяти
	int *matrix; matrix = (int*)calloc(n*m, sizeof(int));
	int *flags; flags = (int*)calloc(n, sizeof(int));

	//ввод матрицы
	int num_string, fail_byte;

	do	{

		fail_byte = 0;

		do {
			cout << "Введите номер строки для ввода: ";
			cin >> num_string;
		} while (num_string <= 0 || num_string > n);
		--num_string;

		if (*(flags + num_string) != 1) {
			*(flags + num_string) = 1;

			for (int j = 0; j < m; j++) {
				cout << "Введите A" << (num_string + 1) << (j + 1) << ": ";
				cin >> *(matrix + num_string * m + j);
			}
		}

		for (int i = 0; i < n; i++)
			if (*(flags + i) != 1)
				fail_byte = 1;

	} while (fail_byte);
	
	//печать
	cout << "\nМатрица: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << *(matrix + i*m + j);
		cout << endl;
	}
}