#include <iostream>
using namespace std;

class Stack
{
private:
	int *_data;
	int _count;
	int _n;

public:

	Stack(int n); // Создание стека
	~Stack(); // Очитска стека

	int Full(); // Проверка на  пустоту
	void Push(int value); // Заносим в стек
	int Pop(); // Извлекаем из мтека с удалением
	int Back(); // Читаем значение на верхушке стека
	int Size(); // Размер стека

	// Сообщения
	void Mes_first() { cout << "Стек пуст" << endl; }
	void Mes_second() { cout << "Стек заполнен." << endl; }
};

Stack::Stack(int n) {
	_n = n; _count = 0;
	_data = new int[_n];	
}

Stack::~Stack(){}

int Stack::Full() {
	if (_count == 0) return 1;
	else if (_count == _n) return -1;
	else return 0;
}

void Stack::Push(int value) {
	_data[_count] = value; 
	_count++;
}

int Stack::Pop() {
	int value = _data[_count - 1];
	_count--;
	return value;
}

int Stack::Back() {
	return _data[_count - 1];
}

int Stack::Size() {
	return _count;
}