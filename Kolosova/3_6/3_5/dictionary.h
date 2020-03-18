#pragma once
/*����������� ����� Dictionary.

����� ������ ������������� ����������� ����������� ����� - ������� �������.

� ����������� �������� ������� ����������� ����� ������������� ����� ���� ������� ����� - �������.

����� ������ ��������� ����������� ��������� ������(������������, ���������� � ��.).

����� ������ ������������� ��������� �������� :

�������� � ������� ����� � ��� �������
�������� ������� ���������� �����,
������ ������� ���������� �����,
��������� ������� ����� � �������,
������ ����� ���� � �������,
��������� ������� � ����, ������� ������� �� �����.
����������� �������� ������������ � ����������� ��������.*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "pss.h"
using namespace std;

class Dict {
private:
	vector<pss> dict;
	int seekpos(string word);
public:
	Dict();
	Dict(const string filename);
	Dict(const Dict& d);
	~Dict();
	void load(const string filename);
	void save(const string filename);
	string translate(const string word);
	pair<int, int> seek(const string word);
	int count();
	int add(const string word, const string translation);
	int changetrans(const string word, const string translation);
	void print();
	Dict& operator=(const Dict& d);
	Dict operator+(const Dict& d);
	Dict& operator+=(const Dict& d);
	Dict& sort_();
};