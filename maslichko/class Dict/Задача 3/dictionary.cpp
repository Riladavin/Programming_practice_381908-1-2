#include "dictionary.h"

Dictionary::Dictionary()
{
}

string Dictionary::print_translation(string name) //�����
{
	it = dict.find(name);

	if (it == dict.end())
	{
		return "������ ����� ��� � �������";
	}
	else
	{
		return it->second;
	}
}

void Dictionary::insert(string eng, string rus) //���������� ���� � �������
{
	dict.insert(make_pair(eng, rus));
}

void Dictionary::change(string eng, string rus) //��������� ��������
{
	it = dict.find(eng);
	if (it == dict.end())
	{
		insert(eng, rus); //���������� � �������
	}
	else
	{ 
		//���������� 
		dict.erase(eng); 
		insert(eng, rus);
	}

}

bool Dictionary::IsExist(string name) //������� ����� � �������
{
	it = dict.find(name);
	if (it == dict.end())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int Dictionary::GetSize() //������ �������
{
	return dict.size();
}

void Dictionary::file_write() //������ � ����
{
	ofstream fout; //�����
	fout.open("dictOut.txt"); // �������� ���� ��� ������

	for (it = dict.begin(); it != dict.end(); it++)
	{
		fout << it->first << " " << it->second << endl;
	}

	fout.close();
}
void Dictionary::file_read()  //������ �� �����
{
	string eng;
	string rus;

	ifstream fout("dictIn.txt"); // �������� ���� ��� ������
	while (!fout.eof())
	{
		fout >> eng >> rus;
		dict[eng] = rus;
	}
	fout.close();
}

const Dictionary Dictionary::operator+(const Dictionary& d)
{
	string eng;
	string rus;

	Dictionary result = d;
	it = dict.begin();
	for (it; it != dict.end(); it++)
	{
		eng = it->first;
		rus = it->second;
		result.insert(eng, rus);
	}
	return result;

}

Dictionary& Dictionary::operator=(const Dictionary& d) //������������
{
	dict = d.dict;
	return *this;
}
