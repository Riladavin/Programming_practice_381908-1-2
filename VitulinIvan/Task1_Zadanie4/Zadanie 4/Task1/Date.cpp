#include <clocale>
#include <iostream>
#include <cstdlib>
#include "ClassDate.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int z, z1;
	cout << "------------------------------------------------��������----------------------------------------------------------------\n";
	do
	{
		cout << "-----������� ����-----\n";
		cout << "1 - ��������� � ����\n";
		cout << "2 - ������� �� ����\n";
		cout << "3 - �������� ��� ����\n";
		cout << "0 - �����\n";
		cout << "����� �����: ";
		cin >> z;
		if (z == 1)
		{
			Date res;
			int days;
			cout << "�������� ����� ����� ����: 1-�� ������; ����� ������-�������: ";
			cin >> z1;
			if (z1 == 1)
			{
				Date DT1;
				cout << "������� ����: \n";
				cin >> DT1;
				cout << "������� ���������� ����: ";
				cin >> days;
				res = DT1.Plus(DT1, days);
				cout << "����� ����: " << res;
				cout << "---------------------\n";
			}
			else
			{
				string DT1;
				Date DT2;
				cout << "������� ����: \n";
				cin >> DT1;
				DT2 = DT2.TRS(DT1);
				cout << "������� ���������� ����: ";
				cin >> days;
				res = DT2.Plus(DT2, days);
				cout << "����� ����: " << res;
				cout << "---------------------\n";
			}
		}
		if (z == 2)
		{
			Date res;
			int days;
			cout << "�������� ����� ����� ����: 1-�� ������; ����� ������-�������: ";
			cin >> z1;
			if (z1 == 1)
			{
				Date DT1;
				cout << "������� ����: \n";
				cin >> DT1;
				cout << "������� ���������� ����: ";
				cin >> days;
				res = DT1.Minus(DT1, days);
				cout << "����� ����: " << res;
				cout << "---------------------\n";
			}
			else
			{
				string DT1;
				Date DT2;
				cout << "������� ����: \n";
				cin >> DT1;
				DT2 = DT2.TRS(DT1);
				cout << "������� ���������� ����: ";
				cin >> days;
				res = DT2.Minus(DT2, days);
				cout << "����� ����: " << res;
				cout << "---------------------\n";
			}
		}
		if (z == 3)
		{
			cout << "�������� ����� ����� ����: 1-�� ������; ����� ������-�������: ";
			cin >> z1;
			if (z1 == 1)
			{
				Date DT1,DT2;
				cout << "������� ������ � ������ ����: \n";
				cin >> DT1;
				cin >> DT2;
				DT2.Comparsion(DT1);
				cout << "---------------------\n";
			}
			else
			{
				string DT1,DT2;
				Date DT1A, DT2A;
				cout << "������� ������ � ������ ����: \n";
				cin >> DT1;
				cin >> DT2;
				DT1A = DT1A.TRS(DT1);
				DT2A = DT2A.TRS(DT2);
				DT2A.Comparsion(DT1A);
				cout << "---------------------\n";
			}
		}
		if ((z != 1) && (z != 2) && (z != 3) && (z != 0))
		{
			cout << "������ 3: �������� �����\n";
			cout << "---------------------\n";
		}
		if (z == 0)
		{
			cout << "-----------------------------------------------���������� ������--------------------------------------------------------\n";
			return 0;
		}
		cout << "���������� ������? 0-���; ����� ������- ��\n";
		cin >> z;
		cout << "\n";
		
	} while (z != 0);
	cout << "-----------------------------------------------���������� ������--------------------------------------------------------\n";
	return 0;
}