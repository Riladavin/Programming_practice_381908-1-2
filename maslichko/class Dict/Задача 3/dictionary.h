#include<iostream>
#include<fstream>
#include <map>

using namespace std;

class Dictionary
{
private:
	map <string, string> dict;
	map <string, string> ::iterator it;
public:
	Dictionary();

	//Dictionary(const Dictionary& d);

	void insert(string eng, string rus); //���������� ���� � �������
	void change(string end, string rus); //��������� ��������
	string print_translation(string name); //�����
	bool IsExist(string name); //������� ����� � �������
	int GetSize(); //������ �������
	void file_write(); //������ � ����
	void file_read(); //������ �� �����
	const Dictionary operator+(const Dictionary& d); //����������� ��������
	Dictionary& operator=(const Dictionary& d); //������������
};