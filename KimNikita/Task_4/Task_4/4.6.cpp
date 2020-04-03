#include "FilmLibrary.h"
#include <locale>
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void PrintMenu()
{
	cout << "����" << endl;
	cout << "-------------------" << endl;
	cout << "0 - ��������� ����� � �����" << endl;
	cout << "1 - �������� �����" << endl;
	cout << "2 - �������� ������ ������ �� ��������" << endl;
	cout << "3 - ����� ����� �� �������� � ����" << endl;
	cout << "4 - ������ ��� ������ ��������� ���������" << endl;
	cout << "5 - ������ ��� ������, �������� � ������ � ��������� ����" << endl;
	cout << "6 - ������ �������� ����� ������� � ����������� �������" << endl;
	cout << "7 - ������ ������ ����� ������� � ����������� ������� � ��������� ����" << endl;
	cout << "8 - ������ ������� ����� �������" << endl;
	cout << "9 - ������� ����� �� ��������" << endl;
	cout << "10 - ����� �� ���������" << endl;
	cout << "� ����� ������ ������ ����� �������� ����" << endl;
}
void PrintMenuEditor()
{
	cout << "�������� �������� ��� ���������:" << endl;
	cout << "1 - ��������" << endl;
	cout << "2 - ��� ���������" << endl;
	cout << "3 - ��� ����������" << endl;
	cout << "4 - ��� �����������" << endl;
	cout << "5 - ���� ������ � ������" << endl;
	cout << "6 - ����� � ������" << endl;
	cout << "0 - ���������� ���������" << endl;
	cout << "� ����� ������ ������ ����� �������� ����" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	ofstream fout;
	ifstream fin("input.txt");
	FilmLibrary fb1;
	fin >> fb1;
	FilmLibrary fb2(fb1);
	Film t;
	vector<Film>v_f;
	string n;
	string f;
	string p;
	int y;
	int c;
	cout << "����� ���������� � �������� ���������� �������" << endl;
	cout << "���� ������ ������������ � � ����������, � ��� ���� ���� input.txt" << endl;
	int v = -1;
	bool e = false;
	bool vis;
	while (true)
	{
		switch (v)
		{
		case 0:
			cin.ignore();
			cout << "������� �������� ����� ��� ����������:" << endl;
			getline(cin, f);
			fout.open(f + ".txt", ios::out);
			cout << "������� �������� ������, ������� ������ ���������:" << endl;
			getline(cin, n);
			cout << "������� ��� ������ � ������:" << endl;
			cin >> y;
			if (fb1.SaveFilm(fout, n, y))
				cout << "������" << endl;
			else
				cout << "������� ������ � ������ ����� ������ � ������ ��� � ����������" << endl;
			fout.close();
			break;
		case 1:
			cin.ignore();
			cout << "������� �������� ������:" << endl;
			getline(cin, t.name);
			cout << "������� ��� ���������:" << endl;
			getline(cin, t.producer);
			cout << "������� ��� ����������:" << endl;
			getline(cin, t.scenarist);
			cout << "������� ��� �����������:" << endl;
			getline(cin, t.composer);
			cout << "������� ���� ������ � ������:" << endl;
			do
			{
				cout << "������� ��� ������ � ������:" << endl;
				cin >> t.date.year;
			} while (t.date.year < 1895);
			vis = false;
			if (t.date.year / 400 > 0 && t.date.year % 400 == 0 || t.date.year % 100 != 0 && t.date.year % 4 == 0)
				vis = true;
			do
			{
				cout << "������� ����� ������ � ������:" << endl;
				cin >> t.date.month;
			} while (t.date.month > 12 || t.date.month < 1);
			fb1.FixMonth(n, y, t.date.month);
			do
			{
				cout << "������� ���� ������ � ������:" << endl;
				cin >> t.date.day;
			} while (t.date.day < 1 || t.date.day>31 || t.date.day > 29 && t.date.month == 2 || t.date.day == 29 && t.date.month == 2 && !vis);
			cout << "������� ����� � ������:" << endl;
			cin >> t.income;
			fb1.AddFilm(t);
			cout << "������";
			break;
		case 2:
			cin.ignore();
			cout << "������� �������� ������, ������ �������� ������ ��������:" << endl;
			getline(cin, n);
			cout << "������� ��� ������ � ������:" << endl;
			cin >> y;
			if (fb1.IsExist(n, y))
			{
				int choice = -1;
				string new_n, new_p, new_s, new_c;
				int new_d, new_m, new_y, new_i;
				while (true)
				{
					switch (choice)
					{
					case 0:
						e = true;
						break;
					case 1:
						cout << "������� ����� �������� ������:" << endl;
						cin.ignore();
						getline(cin, new_n);
						fb1.FixName(n, y, new_n);
						cout << "������" << endl;
						break;
					case 2:
						cout << "������� ����� ��� ���������:" << endl;
						cin.ignore();
						getline(cin, p);
						fb1.FixProducer(n, y, new_p);
						cout << "������" << endl;
						break;
					case 3:
						cout << "������� ����� ��� ����������:" << endl;
						cin.ignore();
						getline(cin, new_s);
						fb1.FixScenarist(n, y, new_s);
						cout << "������" << endl;
						break;
					case 4:
						cout << "������� ����� ��� �����������:" << endl;
						cin.ignore();
						getline(cin, new_c);
						fb1.FixComposer(n, y, new_c);
						cout << "������" << endl;
						break;
					case 5:
						cout << "������� ����� ���� ������ � ������:" << endl;
						do
						{
							cout << "������� ��� ������ � ������:" << endl;
							cin >> new_y;
						} while (new_y < 1895);
						fb1.FixYear(n, y, new_y);
						vis = false;
						if (new_y / 400 > 0 && new_y % 400 == 0 || new_y % 100 != 0 && new_y % 4 == 0)
							vis = true;
						do
						{
							cout << "������� ����� ������ � ������:" << endl;
							cin >> new_m;
						} while (new_m > 12 || new_m < 1);
						fb1.FixMonth(n, y, new_m);
						do
						{
							cout << "������� ���� ������ � ������:" << endl;
							cin >> new_d;
						} while (new_d < 1 || new_d>31 || new_d > 29 && new_m == 2 || new_d == 29 && new_m == 2 && !vis);
						fb1.FixDay(n, y, new_d);
						cout << "������" << endl;
						break;
					case 6:
						cout << "������� ����� � ������:" << endl;
						cin >> new_i;
						fb1.FixIncome(n, y, new_i);
						cout << "������" << endl;
						break;
					default:
						PrintMenuEditor();
					}
					if (e)
					{
						e = false;
						break;
					}
					cin >> choice;
				}
				cout << "������" << endl;
			}
			else
				cout << "������� ������ ��� � ����������" << endl;
			break;
		case 3:
			cin.ignore();
			cout << "������� �������� ������:" << endl;
			getline(cin, n);
			cout << "������� ��� ������ � ������:" << endl;
			cin >> y;
			t = fb1.FindFilm(n, y);
			if (t.name != "")
			{
				t.PrintFilm();
				cout << "������" << endl;
			}
			else
				cout << "������� ������ � ������ ����� ������ � ������ ��� � ����������" << endl;
			break;
		case 4:
			cin.ignore();
			cout << "������� ��� ���������:" << endl;
			getline(cin, p);
			v_f = fb1.GetFilmsBy(p);
			if (v_f.size() != 0)
			{
				for (int i = 0; i < v_f.size(); i++)
				{
					v_f[i].PrintFilm();
				}
				cout << "������" << endl;
			}
			else
				cout << "������� ������� ��������� ��� � ����������" << endl;
			break;
		case 5:
			cout << "������� ��� ������ � ������:" << endl;
			cin >> y;
			v_f = fb1.GetFilmsIn(y);
			if (v_f.size() != 0)
			{
				for (int i = 0; i < v_f.size(); i++)
				{
					v_f[i].PrintFilm();
				}
				cout << "������" << endl;
			}
			else
				cout << "�������, �������� � ������ � ������ ����, ��� � ����������" << endl;
			break;
		case 6:
			cout << "������� ���������� �������, ������� ����� �������:" << endl;
			cin >> c;
			v_f = fb1.GetFilmsMaxIncome(c);
			for (int i = 0; i < v_f.size(); i++)
			{
				v_f[i].PrintFilm();
			}
			cout << "������" << endl;
			break;
		case 7:
			cout << "������� ���������� �������, ������� ����� �������:" << endl;
			cin >> c;
			cout << "������� ��� ������ � ������:" << endl;
			cin >> y;
			v_f = fb1.GetFilmsMaxIncomeIn(c, y);
			if (v_f.size() != 0)
			{
				for (int i = 0; i < v_f.size(); i++)
				{
					v_f[i].PrintFilm();
				}
				cout << "������" << endl;
			}
			else
				cout << "�������, �������� � ������ � ������ ����, ��� � ����������" << endl;
			break;
		case 8:
			cout << "����� �������: " << fb1.Size() << endl;
			cout << "������" << endl;
			break;
		case 9:
			cin.ignore();
			cout << "������� �������� ������, ������� ����� �������:" << endl;
			getline(cin, n);
			if (fb1.DelFilm(n))
				cout << "������" << endl;
			else
				cout << "������� ������ ��� � ����������" << endl;
			break;
		case 10:
			e = true;
			break;
		default:
			PrintMenu();
		}
		if (e)
			break;
		cin >> v;
	}
	ofstream fout2;
	fout2.open("output.txt", ios::out);
	cout << "��������� ����� ������������ � ����� output";
	fout2 << "����:" << endl;
	fout2 << fb2;
	fout2 << "�����:" << endl;
	fout2 << fb1;
	fout2.close();
	return 0;
}
