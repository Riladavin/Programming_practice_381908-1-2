#include<iostream>
#include<string>

using namespace std;

class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time();//�� ���������
	Time(const Time& _d);//������d����
	Time(int _hour, int _min, int _sec);//������������
	Time(string s);//��������������
	~Time();//����������
	void setHour(int _hour);
	void setMin(int _min);
	void setSec(int _sec);
	void setTime(int _hour, int _min, int _sec);
	int getHour() { return hour; }
	int getMin() { return min; }
	int getSec() { return sec; }
	Time getTime();
	Time addHour(int _hour);
	Time addMin(int _min);
	Time addSec(int _sec);
	//ime operator-(const Time& _d);//�������� c ��������������
	//Time operator-(string s); // �������� �� �������
	Time& operator=(const Time& _d); //������������
	Time operator+(const Time& _d);//����� � ��������������
	Time operator+(string s);// ����� �� �������
	Time operator*(const Time& _d); // ������������
	Time operator* (string s);
	bool operator==(const Time& _d);
	friend ostream& operator<<(ostream& stream, const Time& _d);
	friend istream& operator>>(istream& stream, Time& _d);
	void inPut();
	void outPut();
};