#pragma once

#include "Date.h"
#include <string>
#include <locale>

using namespace std;

class Film {
public:
	string name;
	string producer;
	string scenarist;
	string composer;
	Date date;
	long long int income;
	Film() :income(0) {}
	void PrintFilm()
	{
		cout << "��������: " << name << endl;
		cout << "��������: " << producer << endl;
		cout << "���������: " << scenarist << endl;
		cout << "����������: " << composer << endl;
		cout << "���� ������ � ������: ";
		date.PrintDate();
		cout << "����� � ������: " << income << endl;
	}
	Film& operator=(const Film& f)
	{
		setlocale(LC_ALL, "Russian");
		if (this != &f)
		{
			name = f.name;
			producer = f.producer;
			scenarist = f.scenarist;
			composer = f.composer;
			date.day = f.date.day;
			date.month = f.date.month;
			date.year = f.date.year;
			income = f.income;
		}
		return *this;
	}
	~Film() {}
};
