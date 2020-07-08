#include <iostream>
using namespace std;

class Queue
{
private:
	int *_data;
	int _size;

public:
	int _UK,
		_UN;

public:
	Queue(int n) {
		_UK = -1;
		_UN = -1;

		_size = n;
		_data = new int[_size];
	}

	void Push() { // добавление эемента 
		int value;
		if (_UK == -1 && _UN == -1)
		{
			_UK = _UN = 0;

			cout << "Введите элемент: "; cin >> value;
			_data[_UK] = value;

		}
		else
		{		
			if ((_UK == _UN - 1) || (_UN == 0 && _UK == _size - 1))
				cout << "Переполнение!" << endl;
			else
			{
				if (_UK == _size - 1)
					_UK = 0;
				else
					_UK++;

				cout << "Введите элемент: "; cin >> value;
				_data[_UK] = value;
			}
		}
	}

	int Pop()  { // чтение элемента с удалением
		if (Empty())
		{
			int a = _data[_UN];
			Delete();
			return a;
		}
		else
			cout << "Очередь пуста!" << endl;

	}

	void Delete() { //удаление элемента 
		if ( !(Empty()) )
			cout << "Очередь пустая!" << endl;
		else
			if (_UK == _UN)
				_UK = _UN = -1;
			else
			{
				if (_UN == _size - 1)
					_UN = 0;
				else
					_UN++;
			}
	}

	void Display() { // вывод очереди 
		if (!(Empty()))
			cout << "Очередь пустая!" << endl;
		else
			if (_UN <= _UK)
				for (int i = _UN; i <= _UK; i++)
					cout << _data[i] << " ";
			else
			{
				for (int i = _UN; i <= _size - 1; i++)
					cout <<_data[i] << " ";
				for (int i = 0; i <= _UK; i++)
					cout << _data[i] << " ";
			}
		cout << endl;
	}

	int Front() {
		if (!(Empty()))
			cout << "Очередь пустая!" << endl;
		else
			return _data[_UN];
	}

	// проверка на пустоту/заполненость
	int Empty() {
		if (_UN == _UK && _UK == -1) return 0;
		else return 1;
	}

	int Full()	{
		if (_UK == _size - 1 || _UK == _UN - 1) return 1;
		else return 0;
	}

	int Size() {
		return  _size;
	}
};
