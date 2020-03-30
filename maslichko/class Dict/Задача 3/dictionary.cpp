#include "dictionary.h"

Dictionary::Dictionary()
{
}

void Dictionary::print_translation(string name) //�����
{
	it = dict.find(name);

	if (it == dict.end())
	{
		cout << "����� " << name << " ��� � �������" << endl;
	}
	else
	{
		cout << "�������: " << it->second << endl;
	}
}

void Dictionary::insert(string eng, string rus) //���������� ���� � �������
{
	dict.insert(make_pair(eng, rus));
}

void Dictionary::change(string eng) //��������� ��������
{
	string temp;
	it = dict.find(eng);
	if (it == dict.end())
	{
		cout << "����� " << eng << " ��� � �������" << endl;
	}
	else
	{
		dict.erase(eng);
		cout << "������� ����� �������: ";
		cin >> temp;
		insert(eng, temp);
	}

}

void Dictionary::existence(string name) //������� ����� � �������
{
	it = dict.find(name);
	if (it == dict.end())
	{
		cout << "����� " << name << " ��� � �������" << endl;
	}
	else
	{
		cout << "����� " << name << " � ������� ����. �������: " << it->second << endl;
	}
}

int Dictionary::count() //������ �������
{
	return dict.size();
}

void Dictionary::file_write() //������ � ����
{
	ofstream out; //�����
	out.open("dictOut.txt"); // �������� ���� ��� ������

	for (it = dict.begin(); it != dict.end(); it++)
	{
		out << it->first << " " << it->second << endl;
	}

	out.close();
}
void Dictionary::file_read()  //������ �� �����
{
	string eng;
	string rus;

	ifstream in("dictIn.txt"); // �������� ���� ��� ������
	while (!in.eof())
	{
		in >> eng >> rus;
		dict[eng] = rus;
	}
	in.close();
}

void Dictionary::file_read(string name1, string name2) //������ �� ���� ������
{
	string eng;
	string rus;
	
	ifstream in1(name1); // �������� ���� ��� ������
	ifstream in2(name2); // �������� ���� ��� ������
	while (!in1.eof())
	{
		in1 >> eng >> rus;
		dict[eng] = rus;
	}
	while (!in2.eof())
	{
		in2 >> eng >> rus;
		dict[eng] = rus;
	}
	in1.close();
	in2.close();
}

Dictionary& Dictionary::operator=(const Dictionary& d) //������������
{
	dict = d.dict;
	return *this;
}
