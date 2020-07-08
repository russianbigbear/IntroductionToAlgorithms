#include "DList.h"
#include <conio.h>
#include <locale.h>
#define MySize 10

//______________________������� ��� ����� ����� �����___________________________________//
void Input_INT(int *value) 
{
	int flag = 0;
	string str;
	do
	{
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if ((str[i]<'0' && str[i] != '-') || str[i]>'9')
			{
				flag = 1; fflush(stdin); break;
			}
			else
				flag = 0;
		}
		if (flag == 0)
		{
			*value = stoi(str);
		}
		else
			cout << "������ �����. �� ��������� ����� ������! �����������: ";
	} while (flag == 1);
}
//____________________________________________________________________________________//

int main()
{
	setlocale(LC_ALL, "RUS");

	D_List *obj_f = new D_List(); D_List *obj_s = new D_List(); //������

	int size_f, size_s; // ������ �������
	int mas_f[MySize]; int mas_s[MySize]; //������� �������

	cout << "��������� ������� ��� ����������� ������ � ���� � ������������� ��� �� �����������." << endl;
	fflush(stdin);

	do {
		cout << "������� ����� ��������� 1 ������: ";
		Input_INT(&size_f);
	} while (size_f > 10 || size_f <= 0);
	fflush(stdin);
	
	if (size_f <= 0) cout << "��� ��������� - ��� ������." << endl;
	else {
		if (size_f == 1) {
			cout << "���� ��������� 1-��� ������: " << endl;
			Input_INT(&mas_f[0]);

			Make_D_List(mas_f[0], &obj_f, NULL);
			cout << "����� ������, ���������� ���� �������:" << endl; Print_D_List(obj_f);
		}
		else {
			cout << "���� ��������� 1-��� ������: " << endl;
			for (int i = 0; i < size_f; i++)
				Input_INT(&mas_f[i]);

			Make_D_List(mas_f[0], &obj_f, NULL);
			obj_f = Sort_Ascending(obj_f, mas_f, size_f);
			cout << "����� ������:" << endl; Print_D_List(obj_f);
		}
	}

	do {
		cout << "������� ����� ��������� 2 ������: ";
		Input_INT(&size_s);
	} while (size_s > 10 || size_s <= 0);
	fflush(stdin);

	if (size_s <= 0) cout << "��� ��������� - ��� ������." << endl;
	else {
		if (size_s == 1) {
			cout << "���� ��������� 1-��� ������: " << endl;
			Input_INT(&mas_s[0]);

			Make_D_List(mas_s[0], &obj_s, NULL);
			cout << "����� ������, ���������� ���� �������:" << endl; Print_D_List(obj_s);
		}
		else {
			cout << "���� ��������� 2-��� ������: " << endl;
			for (int i = 0; i < size_s; i++)
				Input_INT(&mas_s[i]);

			Make_D_List(mas_s[0], &obj_s, NULL);
			obj_s = Sort_Ascending(obj_s, mas_s, size_s);
			cout << "����� ������:" << endl; Print_D_List(obj_s);
		}
	}

	D_List *obj_t = Add_D_List(obj_f,obj_s);
	int size_t = size_f + size_s;
	int *mas_t = new int[size_t];

	if ((size_s > 0) && (size_f > 0)) {

		for (int i = 0; i < size_f; i++)
			mas_t[i] = mas_f[i];

		for (int i = 0; i < size_s; i++)
			mas_t[size_f + i] = mas_s[i];
	}

	for (int i = 0; i < size_t; i++)
		cout << mas_t[i] << endl;

	if ((size_s > 0) && (size_f > 0)) {
		Make_D_List(mas_t[0], &obj_t, NULL);
		obj_t = Sort_Ascending(obj_t, mas_t, size_t);
		cout << "����� ������:" << endl; Print_D_List(obj_t);
	}

	return 0;
}
