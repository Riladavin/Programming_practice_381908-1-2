#include<iostream>
#include<locale>
#include<algorithm>
#include"Battlefield.h"
#include<cstdlib>

using namespace std;

// ��������� ������������ �������� ��������� � ��������� ������ � ������� ������ ���� ��������� �������
// ���� � ���� ������� ��� �������� � ��� ���� �������, �� false
bool Battlefield::isCorrectlyLocation(int x, int y, int x1, int y1, bool side) { // side == 1 - �� ������� ������������
	if (!(x1 < 10 && x1>=0 && x >= 0 && x < 10 && y < 10 && y>=0 && y1 < 10 && y1 >= 0))
		return false;
	/*if (abs(x1 - x)+1 > 4 || abs(y1 - y)+1 > 4)
		return false;*/
	if (x == y && x1 == y1 && x != x1)// ������� �� ���������
		return false;
	int xmin = min(x, x1);
	int xmax = max(x, x1);
	int ymin = min(y, y1);
	int ymax = max(y, y1);
	if (side) {
		for (int i = xmin; i <= xmax; i++)// ������ 
			for (int j = ymin; j <= ymax; j++) // �� �������
				for (int k = -1; k < 2; k++) // ������ ����� ������
					for (int c = -1; c < 2; c++) // � �������� � ���
						if (i + k >= 0 && i + k < 10 && j + c >= 0 && j + c < 10)
							if (UserField[i + k][j + c] == 1)
								return false;
	}
	else
		for (int i = xmin; i <= xmax; i++)// ������ 
			for (int j = ymin; j <= ymax; j++) // �� �������
				for (int k = -1; k < 2; k++) // ������ ����� ������
					for (int c = -1; c < 2; c++) // � �������� � ���
						if (i + k >= 0 && i + k < 10 && j + c >= 0 && j + c < 10)
							if (CompField[i + k][j + c] == 1)
								return false;					
	return true;
}

void Battlefield::addShip(const Ship& ship, bool side) { // side == 1 - �� ������� ������������
	int x = min(ship.getX(), ship.getX1());
	int x1 = max(ship.getX(), ship.getX1());
	int y = min(ship.getY(), ship.getY1());
	int y1 = max(ship.getY(), ship.getY1());
	if(side)
	for (int i = x; i <= x1; i++)
		for (int j = y; j <= y1; j++)
			UserField[i][j] = 1;
	else
		for (int i = x; i <= x1; i++)
			for (int j = y; j <= y1; j++)
				CompField[i][j] = 1;
}

void Battlefield::addCompShip(int deck) { // deck - ���������� �����
	bool f = false;
	do {
		int x = rand() % 9;
		int y = rand() % 9;
		int x1 = x;
		int y1 = y;
		int Allign = rand() % 10;
		if (Allign % 2)// vertical or horizontal 
			x1 += deck-1;
		else
			y1 += deck-1;
		if (isCorrectlyLocation(x, y, x1, y1, false)) {
			f = true;
			Ship ship(x, y, x1, y1);
			this->addShip(ship, false);
		}
	} while (!f);
}

bool Battlefield::userShot(int x, int y) {
	if (CompField[x][y] == 1) { // ����������
		CompField[x][y] = -2;
		return 1;
	}
	if (CompField[x][y] == 0) { //������
		CompField[x][y] = -1;
		return 0;
	}
}

int Battlefield::operator()(int x, int y, string side) {
	if (x > 9 || y > 9 || x < 0 || y < 0 || (side != "User" && side != "Comp"))
		throw - 1;
	if (side == "Comp")
		return CompField[x][y];
	if (side == "User")
		return UserField[x][y];
}

bool Battlefield::isGameOver() {
	bool res1 = false;
	bool res2 = false;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (UserField[i][j] == 1) {
				res1 = true;
				break;
			}
			if (CompField[i][j] == 1) {
				res2 = true;
				break;
			}
		}
	if (res1 && res2)
		return false;
	return true;
}

string Battlefield::printHelpUser(int a) const{
	if (a == -2)
		return "X";
	if (a == -1)
		return "*";
	if (a == 1)
		return "K";
	if (a == 0)
		return "O";
}

string Battlefield::printHelpComp(int a) const{
	if (a == -2)
		return "X";
	if (a == -1)
		return "*";
	if (a == 0 || a== 1)
		return "O";
}

ostream& operator<< (ostream& stream, const Battlefield& field) {
	stream << " ���� ����:                   ���� ��:" << "\n";
	stream << "  ";
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < 10; i++) {
			stream << "|" << field.ABC[i];
		}
		stream << "|        ";
	}
	stream << "\n";
	for (int i = 0; i < 9; i++) {
		stream << " " << i + 1;
		for (int j = 0; j < 10; j++) {
			stream << "|" << field.printHelpUser(field.UserField[j][i]);
		}
		stream << "|       " << i + 1;
		for (int j = 0; j < 10; j++) {
			stream << "|" << field.printHelpComp(field.CompField[j][i]);
		}
		stream << "|";
		stream << "\n";
	}
	stream << 10;
	for (int j = 0; j < 10; j++) {
		stream << "|" << field.printHelpUser(field.UserField[j][9]);
	}
	stream << "|      " << 10;
	for (int j = 0; j < 10; j++) {
		stream << "|" << field.printHelpComp(field.CompField[j][9]);
	}
	stream << "|\n";
	return stream;
}