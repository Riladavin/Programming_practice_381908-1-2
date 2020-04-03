#pragma once

#include "Film.h"
#include<vector>
#include <fstream>

class FilmLibrary {
private:
	vector<Film> lib;
	friend bool sort_year_name(const Film& a, const Film& b);
	friend bool sort_income(const Film& a, const Film& b);
public:
	FilmLibrary() {}
	FilmLibrary(const FilmLibrary&);
	bool SaveFilm(ofstream&, string, int);
	void AddFilm(Film);
	bool IsExist(string, int);
	bool FixName(string, int, string);
	bool FixProducer(string, int, string);
	bool FixScenarist(string, int, string);
	bool FixComposer(string, int, string);
	bool FixYear(string, int, int);
	bool FixMonth(string, int, int);
	bool FixDay(string, int, int);
	bool FixIncome(string, int, int);
	Film FindFilm(string, int);
	vector<Film> GetFilmsBy(string);
	vector<Film> GetFilmsIn(int);
	vector<Film> GetFilmsMaxIncome(int);
	vector<Film> GetFilmsMaxIncomeIn(int, int);
	int Size();
	bool DelFilm(string);
	friend ifstream& operator>> (ifstream&, FilmLibrary&);
	friend ofstream& operator<<(ofstream&, const FilmLibrary&);

	~FilmLibrary() {}
};
