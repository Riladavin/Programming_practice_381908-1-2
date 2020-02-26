#pragma once
/* ����� ������ ��������� ��� ����������� ������������ � ����������.

� ������ ������ ���� ����������� ��������:
������������
4 ����������� �������������� ��������
���������
����� / ������ � ����� */

#include <iostream>
using namespace std;

int NOD(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

class Rational {
private:

	int n, m;

public:

	Rational();

	Rational(int a, int b);

	Rational(int x);

	Rational(const Rational& b);

	~Rational();

	Rational operator+(Rational& a);

	Rational operator-(Rational& a); 

	Rational operator*(Rational& a);

	Rational operator/(Rational& a);

	void simplify();

	Rational& operator=(Rational& a);

	bool operator==(const Rational& a);

	bool operator!=(const Rational& a);

	bool operator>(const Rational & a);

	bool operator<(const Rational & a);

	friend istream& operator>>(istream&, Rational&);

	friend ostream& operator<<(ostream&, const Rational&);
};