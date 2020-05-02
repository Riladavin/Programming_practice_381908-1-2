#include "TicketOffice.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <algorithm>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russia");
	ifstream fin("input.txt");
	Cinema mycinema;
	fin >> mycinema;
	TicketOffice ticketoffice(mycinema);
	DateS t_date;
	TimeS t_time;
	int day, month, hour, minute;
	cout << "������� ������� ���� � �����: " << endl;
	cin >> day >> month >> hour >> minute;
	try
	{
		ticketoffice.SetCurrentDateSTimeS(DateS(day, month), TimeS(hour, minute));
		t_date = DateS(29, 4);
		t_time = TimeS(14, 0);
		if (ticketoffice.IsFree(t_date, t_time, 1, 20, 1))
		{
			cout << "����� ��������" << endl;
			ticketoffice.PrintSeanceHall(t_date, t_time, 1);
			ticketoffice.Reserve(1, t_date, t_time, 1, 20, 1);
			cout << "����� ���������������" << endl;
			ticketoffice.PrintSeanceHall(t_date, t_time, 1);
		}
		else
			cout << "����� ������" << endl;
		double sum = ticketoffice.CalculateCost(1, t_date, t_time, 1);
		cout << "��������� ������� �� ��������� �����: " << sum << endl;
		cout << "����������� ������� ��" << endl;
		if (ticketoffice.Reserve(1, t_date, t_time, 1, 20, 1))
			cout << "����� ���������������" << endl;
		else
		{
			cout << "��� ������ ���-�� ��������� ����" << endl;
			if (ticketoffice.CancelOrder(1, t_date, t_time, 1))
			{
				cout << "����� �������" << endl;
				ticketoffice.PrintSeanceHall(t_date, t_time, 1);
				if (ticketoffice.Reserve(1, t_date, t_time, 1, 20, 1))
				{
					cout << "����� ���������������" << endl;
					ticketoffice.PrintSeanceHall(t_date, t_time, 1);
				}
				else
					cout << "����� �� ������� ���������������" << endl;
			}
			else
				cout << "����� �� ������� ��������" << endl;
		}
		vector<Ticket> mytickets = ticketoffice.CreateTickets(1, t_date, t_time, 1);
		cout << "���� ������:" << endl << endl;
		for (int i = 0; i < mytickets.size(); i++)
		{
			mytickets[i].PrintTicket();
		}
		cout << "�������������� �����: " << endl << endl;
		t_date = DateS(1, 5);
		t_time = TimeS(10, 59);
		ticketoffice.TicketsOrder(1, t_date, t_time, 4, 12, 0, mytickets);
		cout << "���� ������:" << endl << endl;
		for (int i = 0; i < mytickets.size(); i++)
		{
			mytickets[i].PrintTicket();
		}
	}
	catch (exception exp)
	{
		cout << exp.what();
	}
	return 0;
}