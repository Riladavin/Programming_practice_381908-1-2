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
	Dictionary(const Dictionary& d);

	void insert(string eng, string rus); //���������� ���� � �������
	void change(string end); //��������� ��������
	void print_translation(string name); //�����
	void existence(string name); //������� ����� � �������
	int count(); //������ �������
	void file_write(); //������ � ����
	void file_read(); //������ �� �����
	void file_read(string file_name1, string file_name2); //������ �� ���� ������
	Dictionary& operator=(const Dictionary& d); //������������
};