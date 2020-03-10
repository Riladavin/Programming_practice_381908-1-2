#include <iostream>
#include <string>
#include <locale>

using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time(string s);
	Time();
	Time(const Time& t);
	Time(int _hour, int _min, int _sec);
	~Time();
	void Print();
	void SetHour(int _hour);
	void SetMin(int _min);
	void SetSec(int _sec);
	void inPut();
	int GetHour();
	int GetMin();
	int GetSec();
	Time& operator=(const Time& t);//�������������
	Time operator+(const Time& t);//����� 
	Time operator-(const Time& t);//��������
	bool operator==(const Time& t);//���������
	bool operator<(const Time& t);//��������� ������
	bool operator<=(const Time& t);//��������� ������ �����
	bool operator>(const Time& t);//��������� ������
	bool operator>=(const Time& t);//��������� ������ �����
	bool operator!=(const Time& t);//��������� �� �����
	friend ostream& operator<<(ostream& stream, const Time& t);
	friend istream& operator>>(istream& stream, Time& t);
};