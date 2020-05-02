#pragma once

#include "DateS.h"
#include "TimeS.h"
#include <string>
#include <vector>

struct Place
{
	bool free;
	bool vip;
};

class Sean�e
{
public:
	DateS date;
	TimeS time;
	string film;
	int num_zal;
	double cost_base;
	vector<vector<Place>> hall;
	Sean�e() :num_zal(0), cost_base(0) {}
	Sean�e(DateS, TimeS, string, int, double);
	Sean�e& operator=(const Sean�e&);
	friend ifstream& operator>>(ifstream&, Sean�e&);
	friend ofstream& operator<<(ofstream&, const Sean�e&);
	~Sean�e() {}
};

