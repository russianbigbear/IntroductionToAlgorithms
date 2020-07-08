#include <iostream>
#include <locale>
#include <conio.h>
using namespace std;

struct number {
	int num;
	number *next,
		*prev;

};

class List {
private:
	number *head;
public:
	void HeadNum(int num) { head->num = num; }
	void Add(int numAdd);
	void Show(int count);
	void SortUp();
	void SortDown();
	void DelNext(number *Head);
	int DeleteAB(int A, int B, int ListC);

	List();
	~List();
};

// ����������� ������ List.
List::List() {
	head = new number();
	head->next = head;
	head->prev = head;
	head->num = 0;
}

// ���������� ������ List.
List::~List() {
	head->next = head;
	head->prev = head;
	head->num = 0;
}

// ���������� � ������.
void List::Add(int numAdd) {
	//��� ��� ������ �������� �����  �����������, �� �� ������ ����� ���� �������-������, � ��������� 0
	number *end = head;
	while (end->next != head) end = end->next; // ��� �� ����� ������.

	number *newNum = new number();
	newNum->num = numAdd;

	newNum->next = head;
	newNum->prev = end;
	end->next = newNum;
	head->prev = newNum;

}

// ������ ������.
void List::Show(int count) {

	number *flow = head;
	for (int i = 0; i < count; i++) {
		cout << flow->num << " ";
		flow = flow->next;
	}

	cout << endl;
}

//���������� �� �����������
void List::SortUp() {

	number *n1 = head,
		*n2 = head;

	do {
		n2 = n1;

		do {
			if (n1->num > n2->num)
				std::swap(n1->num, n2->num);
			n2 = n2->next;
		} while (n2 != head);

		n1 = n1->next;
	} while (n1 != head);
}

//���������� �� ��������
void List::SortDown(){
	number *n1 = head,
		*n2 = head;

	do {
		n2 = n1;

		do {
			if (n1->num < n2->num)
				std::swap(n1->num, n2->num);
			n2 = n2->next;
		} while (n2 != head);

		n1 = n1->next;
	} while (n1 != head);
}

/*�������� ��������� � ������*/
void List::DelNext(number *Head) {
	number *newNum = Head->next;
	if (newNum == head) head = Head->next->next;
	Head->next = Head->next->next;
	Head->next->prev = Head;
	delete(newNum);
}

// �������� ������ ����� [a,b]
int List::DeleteAB(int A, int B, int ListC) {
	int DelNum = 0;
	if (A <= B) {
		int max, min;
		if (A > B) { max = A; min = B; }
		else { max = B; min = A; }
		DelNum = (max - min) + 1;
	}
	else {
		for (int i = A; i <= ListC; i++) DelNum++;
		DelNum += B;
	}

	number *curA = head;

	for (int i = 1; i < A; i++)
		curA = curA->next;
	curA = curA->prev;

	if (DelNum != ListC)
		for (int i = 0; i < DelNum; i++) {
			DelNext(curA);
		}

	else
		delete this;

	return ListC - DelNum;

}