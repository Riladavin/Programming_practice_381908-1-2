#pragma once
#include "Sean�e.h"

class Cinema
{
private:
	friend bool sort_date_time_hall(const Sean�e&, const Sean�e&);
public:
	vector<Sean�e> seanses;
	Cinema() {}
	Cinema& operator=(const Cinema&);
	friend ifstream& operator>>(ifstream&, Cinema&);
	friend ofstream& operator<<(ofstream&, const Cinema&);
	~Cinema() {}
};

