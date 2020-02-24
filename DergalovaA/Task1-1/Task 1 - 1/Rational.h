#pragma once
/* ����������� ����� Rational(������������ �����).

����� ������ ������� ���������� ����� n / m(����������� �� ����� 0).

����� ������ ��������� � ������������ ����.

����� ������ ��������� ��� ����������� ������������ � ����������.

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

private:
	int n, m;

public:
	Rational plus(Rational& a, Rational& b);

	Rational minus(Rational& a, Rational& b); 

	Rational mult(Rational& a, Rational& b);

	Rational div(Rational& a, Rational& b);

	Rational simplify(Rational a);

	Rational inicialize(int a, int b);

	void sravn(Rational& a, Rational& b);

	void input();

	void output(Rational& a);
};