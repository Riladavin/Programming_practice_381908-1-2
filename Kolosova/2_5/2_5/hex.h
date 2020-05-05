#pragma once
/*������� ����� Hex ��� ������ � ������������ ������ ������������������ �������, ��������� ��� ������������� ����� ������ �� ��������� ���� 
unsigned char, ������ �� ������� �������� ����������������� ������.

������� ����� ����� ������� ������.

������ ������� �������� ��� �������� ������������. ����������� ��������:

������������
��������������: +, -
���������
�������� ���������� � ��������� ������ ������� �� ������� �������.
�������� << � >> ��� ���������� ���� � ����� � ������ �� �����*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
using namespace std;

class Hex {
private:
	vector<bitset<5>> d;
public:
	Hex();
	Hex(const Hex& h);
	Hex(string s);
	~Hex();
	vector<bitset<5>>& get_d();
	int get_size();
	string toString() const;
	friend Hex stoh(string s);
	Hex& operator=(const Hex& h);
	Hex& operator=(const string& h);
	Hex operator+(const Hex& h);
	Hex operator-(const Hex& h);
	bool operator<(const Hex& a) const;
	bool operator>(const Hex& a) const;
	bool operator<=(const Hex& a);
	bool operator>=(const Hex& a);
	bool operator==(const Hex& a);
	bool operator!=(const Hex& a);
	Hex& operator+=(const Hex& h);
	Hex& operator-=(const Hex& h);
	bitset<5> & operator[](const int index);
	

	friend istream& operator>>(istream& in, Hex& a);
	friend ostream& operator<<(ostream& out, const Hex& a);
	friend ifstream& operator>>(ifstream& in, Hex& a);
	//friend ofstream& operator<<(ofstream& out, const Hex& a);
	
};
