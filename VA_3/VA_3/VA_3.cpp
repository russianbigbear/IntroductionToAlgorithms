#include "SList.h"
#include <locale.h>

int main() {

	setlocale(LC_ALL, "rus");
	int POVT;
	int IP;

	S_List *SL_POVT;
	S_List *SL_IP;

	do {
		do {
			cout << "Введите количество абитуриентов ПОВТ: ";
			ignorecin;
		} while (!(cin >> POVT));
		clearcin;
	} while (POVT <= 0 || POVT > 100);
	Create_S_List(POVT, &SL_POVT);

	do {
		do {
			cout << "Введите количество абитуриентов ИП: ";
			ignorecin;
		} while ( !(cin >> IP) );
		clearcin;
	} while (IP <= 0 || IP > 100);
	Create_S_List(IP, &SL_IP);

	cout << "\nСписок абитуриентов ПОВТ:" << endl;
	Print_S_List(SL_POVT);
	cout << "\nСписок абитуриентов ИП:" << endl;
	Print_S_List(SL_IP);

	S_List *SC;


	if (Compare_S_List(SL_POVT, SL_IP, &SC)) {
		cout << "\nСписок абитуриентов, на ПОВТ и ИП:" << endl;
		Print_S_List(SC);
		Delete_S_List(SC);
	}
	Delete_S_List(SL_POVT); Delete_S_List(SL_IP);

	return 0;
}