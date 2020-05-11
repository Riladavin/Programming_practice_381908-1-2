#ifndef FILM_CLASS
#define FILM_CLASS

#include "FilmLibrary.h"

class FilmClass : public FilmLibrary   //����������� �����
{
public:
    FilmClass() : FilmLibrary()   // ����������� ������ FilmClass �������� ����������� ������ FilmLibrary
    {
    }
    void Add(string title, string producer, string screenwriter, string composer, string data, long long fees); //�������� �����
	void Change(string title, string producer, string screenwriter, string composer, string data, long long fees); // �������� ������ ������ ���������� �� ��������
	vector<string> Find(string title, int year); //����� ����� �� �������� � ����
	vector<string> MovieSearch(string producer); //������ ��� ������ ��������� ���������
	vector<string> MovieSearch(int year); //������ ��� ������, �������� � ������ � ��������� ����
	vector<string> NumberFilms(int quantity); //������ �������� ����� ������� � ����������� �������
	vector<string> NumberFilms(int quantity, int year); //������ �������� ����� ������� � ����������� ������� � ��������� ����
	int Total(); //������ ������� ����� �������
	void DeleteMovie(string title); //�������� ���������� � ������
	void SaveLibraru(); //��������� � ����
	void ReadLibraryr(); //������� �� �����

	string ParseDate(string data); //�������� ��� �� ����
};

#endif