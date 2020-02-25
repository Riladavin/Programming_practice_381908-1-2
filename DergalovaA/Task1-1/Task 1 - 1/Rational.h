#pragma once
/* ����� ������ ��������� ��� ����������� ������������ � ����������.

� ������ ������ ���� ����������� ��������:
������������
4 ����������� �������������� ��������
���������
����� / ������ � ����� */

#include <iostream>
using namespace std;

int NOD(int n, int m)
{
	while (n != 0 && m != 0)
		if (n > m) n %= m; else n %= m;
	return n + m;
}

class Rational {

public:
	int n, m;

	Rational operator+(Rational& a);

	Rational operator-(Rational& a); 

	Rational operator*(Rational& a);

	Rational operator/(Rational& a);

	void simplify();

	Rational& operator=(Rational& a);

	bool operator==(const Rational& a);

	bool operator!=(const Rational& a);


	void input();

	void output(Rational& a);
};