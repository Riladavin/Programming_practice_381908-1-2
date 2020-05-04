#include"ArtInt.h"

using namespace std;

AI::AI() {
	HitCount = -1;
	LastHit.resize(4);
	for (int i = 0; i < 4; i++) {
		LastHit[i].first = LastHit[i].second = -1;
	}
	for(int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			points.push_back(make_pair(i, j));
	srand(time(NULL));
}

bool AI::randomShoot(Battlefield& field, int& x, int& y) {
	int k = rand() % points.size();
	pair<int, int> point = points[k];
	points.erase(points.begin() + k);
	x = point.first;
	y = point.second;
	if (field.UserField[point.first][point.second] == 1){
		HitCount++;
		LastHit[HitCount] = point;
		AIField[point.first][point.second] = -2;//��������� � �����
		field.UserField[point.first][point.second] = -2;
		return true;
	}
	else {
		AIField[point.first][point.second] = -1; // �����������
		field.UserField[point.first][point.second] = -1;
		return false;
	}
}
//�������� �� ��������� � �� ����������� �� ������, � ������� ��������� ��������� �������
// � ������� ���� ����������� ��������� ���������
bool AI::smartShoot(Battlefield& field, int& x, int& y) {
	while (1) {
		int i = LastHit[HitCount].first;
		int j = LastHit[HitCount].second;
		if (i + 1 < 10 && AIField[i + 1][j] == 0) { // ������ �����
			if (field.UserField[i + 1][j] == 0) {// ������
				field.UserField[i + 1][j] = -1;
				AIField[i + 1][j] = -1;
				x = i + 1;
				y = j;
				return false;
			}
			if (field.UserField[i + 1][j] == 1) { // ���������
				field.UserField[i + 1][j] = -2;
				AIField[i + 1][j] = -2;
				HitCount++;
				LastHit[HitCount] = make_pair(i + 1, j);
				x = i + 1;
				y = j;
				return true;
			}
		}
		if (j + 1 < 10 && AIField[i][j + 1] == 0) { // ������ ������
			if (field.UserField[i][j + 1] == 0) {// ������
				field.UserField[i][j + 1] = -1;
				AIField[i][j + 1] = -1;
				x = i;
				y = j+1;
				return false;
			}
			if (field.UserField[i][j + 1] == 1) { // ���������
				field.UserField[i][j + 1] = -2;
				AIField[i][j + 1] = -2;
				HitCount++;
				LastHit[HitCount] = make_pair(i, j + 1);
				x = i;
				y = j + 1;
				return true;
			}
		}
		if (i - 1 >= 0 && AIField[i - 1][j] == 0) { // ������ ������
			if (field.UserField[i - 1][j] == 0) {// ������
				field.UserField[i - 1][j] = -1;
				AIField[i - 1][j] = -1;
				x = i - 1;
				y = j;
				return false;
			}
			if (field.UserField[i - 1][j] == 1) { // ���������
				field.UserField[i - 1][j] = -2;
				AIField[i - 1][j] = -2;
				HitCount++;
				LastHit[HitCount] = make_pair(i - 1, j);
				x = i - 1;
				y = j;
				return true;
			}
		}
		if (j - 1 >= 0 && AIField[i][j - 1] == 0) { // ������ �����
			if (field.UserField[i][j - 1] == 0) {// ������
				field.UserField[i][j - 1] = -1;
				AIField[i][j - 1] = -1;
				x = i;
				y = j - 1;
				return false;
			}
			if (field.UserField[i][j - 1] == 1) { // ���������
				field.UserField[i][j - 1] = -2;
				AIField[i][j - 1] = -2;
				HitCount++;
				LastHit[HitCount] = make_pair(i, j - 1);
				x = i;
				y = j - 1;
				return true;
			}
		}
		HitCount = 0;// ������� � ������, � ������� ������, 
	}
}


bool AI::isUserShipDestroyed(Battlefield& field) {// bfs ������� ����� �� ������������ �������� �� �����, �� ������� ����� � ��������� ���
	queue <pair<int, int>> decks; 
	bool was[10][10]{};
	int x = LastHit[HitCount].first;
	int y = LastHit[HitCount].second;
	decks.push(make_pair(x, y));
	while (!decks.empty()) {
		int i = decks.front().first;
		int j = decks.front().second;
		decks.pop();
		was[i][j] = true;
		if (i - 1 >= 0 && field.UserField[i - 1][j] == -2 && was[i - 1][j]==false)// �������� ������ ������, ���� ��� ������������ �����, �� �������� � �������
			decks.push(make_pair(i - 1, j));
		if (i - 1 >= 0 && field.UserField[i - 1][j] == 1)// ���� � ������ ������ ���� ����� ����� �������
			return false;
		if (i + 1 <= 9 && field.UserField[i + 1][j] == -2 && was[i + 1][j] == false)// ������ �����
			decks.push(make_pair(i + 1, j));
		if (i + 1 <= 9 && field.UserField[i + 1][j] == 1)
			return false;
		if (j - 1 >= 0 && field.UserField[i][j - 1] == -2 && was[i][j - 1] == false)// ������ �����
			decks.push(make_pair(i, j - 1));
		if (j - 1 >= 0 && field.UserField[i][j - 1] == 1)
			return false;
		if (j + 1 <= 9 && field.UserField[i][j + 1] == -2 && was[i][j + 1] == false)// ������ ������
			decks.push(make_pair(i, j + 1));
		if (j + 1 <= 9 && field.UserField[i][j + 1] == 1)
			return false;
	}
	return true;
}

bool AI::isCompShipDestroyed(Battlefield& field, int x, int y) { // ����� �� bfs, �� ��� ���� CompField
	queue <pair<int, int>> decks;
	bool was[10][10]{};
	decks.push(make_pair(x, y));
	while (!decks.empty()) {
		int i = decks.front().first;
		int j = decks.front().second;
		decks.pop();
		was[i][j] = true;
		if (i - 1 >= 0 && field.CompField[i - 1][j] == -2 && was[i - 1][j] == false)// �������� ������ ������, ���� ��� ������������ �����, �� �������� � �������
			decks.push(make_pair(i - 1, j));
		if (i - 1 >= 0 && field.CompField[i - 1][j] == 1)// ���� � ������ ������ ���� ����� ����� �������
			return false;
		if (i + 1 <= 9 && field.CompField[i + 1][j] == -2 && was[i + 1][j] == false)// ������ �����
			decks.push(make_pair(i + 1, j));
		if (i + 1 <= 9 && field.CompField[i + 1][j] == 1)
			return false;
		if (j - 1 >= 0 && field.CompField[i][j - 1] == -2 && was[i][j - 1] == false)// ������ �����
			decks.push(make_pair(i, j - 1));
		if (j - 1 >= 0 && field.CompField[i][j - 1] == 1)
			return false;
		if (j + 1 <= 9 && field.CompField[i][j + 1] == -2 && was[i][j + 1] == false)// ������ ������
			decks.push(make_pair(i, j + 1));
		if (j + 1 <= 9 && field.CompField[i][j + 1] == 1)
			return false;
	}
	return true;
}

// ������� bfs, ������ � ��������� ������, �� ������� ����� ��������, ������ �������
void AI::deleteExcessPoints(Battlefield& field) {
	queue <pair<int, int>> decks;
	bool was[10][10]{};
	int x = LastHit[HitCount].first;
	int y = LastHit[HitCount].second;
	decks.push(make_pair(x, y));
	while (!decks.empty()) {
		int i = decks.front().first;
		int j = decks.front().second;
		was[i][j] = true;
		decks.pop();

		for(int c=-1; c<2; c++) // �������� ����� ������ ������������� �������
			for (int k = -1; k < 2; k++) {
				pair<int, int> point;
				point.first = i + c;
				point.second = j + k;
				for(int i1=0; i1<points.size(); i1++)
					if (point == points[i1]) {
						points.erase(points.begin() + i1);
						break;
					}
			}

		if (i - 1 >= 0 && field.UserField[i - 1][j] == -2 && was[i - 1][j] == false)// �������� ������ ������, ���� ��� ��� �������, �� �������� � �������
			decks.push(make_pair(i - 1, j));
		if (i + 1 <= 9 && field.UserField[i + 1][j] == -2 && was[i + 1][j] == false)// ������ �����
			decks.push(make_pair(i + 1, j));
		if (j - 1 >= 0 && field.UserField[i][j - 1] == -2 && was[i][j - 1] == false)// ������ �����
			decks.push(make_pair(i, j - 1));
		if (j + 1 <= 9 && field.UserField[i][j + 1] == -2 && was[i][j + 1] == false)// ������ ������
			decks.push(make_pair(i, j + 1));
	}
	HitCount = -1;
	for (int i = 0; i < 4; i++)
		LastHit[i].first = LastHit[i].second = -1;
}
