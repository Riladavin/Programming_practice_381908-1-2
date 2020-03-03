#pragma once
#include <iostream>
using namespace std;

class Date
{
	private:
		int d, m, y;
	public:
		Date();//����������� �� ���������
		Date TRS(string TRSdate);
		Date operator= (const Date& dt);
		Date Minus(const Date& dt, int dm);
		Date Plus(const Date& dt, int dp);
		friend std::istream& operator>>(istream& stream, Date& dt);
		friend std::ostream& operator<<(ostream& stream, const Date& dt);
		void Comparsion(const Date& dt1);
		
};
