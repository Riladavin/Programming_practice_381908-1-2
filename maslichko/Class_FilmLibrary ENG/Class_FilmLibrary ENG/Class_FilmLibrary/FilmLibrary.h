#include<iostream>
#include<fstream>
#include <vector>

using namespace std;

class FilmLibrary
{
private:
	vector<string> title_vector;
	vector<string> producer_vector;
	vector<string> screenwriter_vector;
	vector<string> composer_vector;
	vector<string> data_vector;
	vector<long long> fees_vector;
public:
	FilmLibrary();

	void Add(string title, string producer, string screenwriter, string composer, string data, long long fees); //�������� �����
	void Change(string title); // �������� ������ ������ ���������� �� ��������
	void Find(string title, int year); //����� ����� �� �������� � ����
	void MovieSearch(string producer); //������ ��� ������ ��������� ���������
	void MovieSearch(int year); //������ ��� ������, �������� � ������ � ��������� ����
	void NumberFilms(int quantity); //������ �������� ����� ������� � ����������� �������
	void NumberFilms(int quantity, int year); //������ �������� ����� ������� � ����������� ������� � ��������� ����
	int Total(); //������ ������� ����� �������
	void DeleteMovie(string title); //�������� ���������� � ������
	void SaveLibraru(); //��������� � ����
	void ReadLibraryr(); //������� �� �����

	string ParseDate(string data); //�������� ��� �� ����
};

