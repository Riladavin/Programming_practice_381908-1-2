#include <iostream>
#include <string>
#include <locale>
#include"Time.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	string s;
	cout << "������� ����� � ������� ��:��:��" << endl;
	cin >> s;
	Time a(s);
	a.Print();
	Time b = { "01:21:10"};
	Time c;
	c = (a - b);
	c.Print();
	Time d;
	d = (a + b);
	cout << d;
	bool f;
	f = (a == b);
	cout << f << endl;
	f = (a > b);
	cout << f << endl;
	f = (a >= b);
	cout << f << endl;
	f = (a != b);
	cout << f << endl;
	cout << "exit";
}