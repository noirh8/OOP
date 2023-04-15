#pragma once
#include <iostream>
using namespace std;
class CTime
{
private:
	int hour, min, sec;
public:
	CTime(int gio = 0, int phut = 0, int giay = 0)
	{
		hour = gio;
		min = phut;
		sec = giay;
	}
	~CTime() { }
	int GetHour();
	int GetMinute();
	int GetSecond();
	long GetTotalSecond();
	CTime operator + (int&);
	CTime operator - (int&);
	CTime operator - (CTime&);
	CTime operator ++ (int);
	CTime operator -- (int);
	friend istream& operator >> (istream& is, CTime& time);
	friend ostream& operator << (ostream& os, CTime& time);
};

