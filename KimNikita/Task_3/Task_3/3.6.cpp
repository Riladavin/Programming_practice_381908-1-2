#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include "Dictionary.h"
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ofstream fout;
	fout.open("output.txt", ios::out);
	ifstream fin("input.txt");
	vector<pair<string, string>> s = { make_pair("Car","������"),make_pair("doG","������"),make_pair("girl","�������"),make_pair("PEN","�����") };
	Dictionary d1, d2(s), d3(d2);
	fin >> d1;
	fout << "d1:" << endl;
	fout << d1;
	fout << "d2:" << endl;
	fout << d2;
	fout << "d3:" << endl;
	fout << d3;

	fout << "d2.add(andromeda, ���������):" << endl;
	d2.add("andromeda", "���������");
	fout << d2;
	fout << "d3.add(Vasya, ����):" << endl;
	d3.add("Vasya", "����");
	fout << d3;

	if (d3.find("vasya"))
	{
		d3.change_translate("vasya", "�������");
		fout << "d3.change_translate(vasya, �������)" << endl;
		fout << "d3.get_translate(vasya):" << endl;
		fout << d3.get_translate("vasya") << endl;
	}

	d1 += d2 + d3;
	fout << "d1 += d2 + d3:" << endl;
	fout << d1;
	fout << "d1.size:" << endl;
	fout << d1.size();
	fout.close();
	fin.close();
	return 0;
}