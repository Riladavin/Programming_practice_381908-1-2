#include <iostream>
#include <fstream>
#include "dictionary.h"
#include <windows.h>

int main()
{
	SetConsoleCP(1251); //��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); //� ����� ������

	int menu;
	string test1, test2, test3, test4;
	Dictionary d1, d2, d3;

	while (1)
	{
		cout << endl;
		cout << "1. �������� � ������� ����� � ��� �������" << endl;
		cout << "2. �������� ������� �����" << endl;
		cout << "3. ������ ������� �����" << endl;
		cout << "4. ��������� ������� ����� � �������" << endl;
		cout << "5. ������ ����� ���� � �������" << endl;
		cout << "6. ��������� ������� � ����" << endl;
		cout << "7. ������� ������� �� �����" << endl;
		cout << "8. ���������� �������" << endl;
		cout << "9. ������������" << endl;
		cout << endl << "�������� ������ ��������: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			cout << "������� ���� ����" << endl;
			cin >> test1 >> test2;
			d1.insert(test1, test2);
			break;
		case 2:
			cout << "�����, � �������� ����� �������� ������� � ����� �������: ";
			cin >> test3 >> test4;
			d1.change(test3, test4);
			break;
		case 3:
			cout << "������� �����, � �������� ����� ������ �������: ";
			cin >> test3;
			cout << d1.translate(test3);
			break;
		case 4:
			cout << "������� �����, ������� ����� �����: ";
			cin >> test3;
			cout << d1.IsExist(test3);
			break;
		case 5:
			cout << "���������� ���� � �������: " << d1.GetSize() << endl;
			break;
		case 6:
			d1.file_write();
			break;
		case 7:
			d2.file_read();
			break;
		case 8:
			d3 = d1 + d2;
			break;
		case 9:
			d2 = d1;
			break;
		}
	}

	system("pause");
}
