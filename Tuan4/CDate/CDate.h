#pragma once
#include <iostream>
using namespace std;

class CDate
{
private:
	int ngay, thang, nam;
	int NgayTrongThang(int, int) const;
public:
	CDate(int day = 0, int month = 0, int year = 0)
	{
		ngay = day;
		thang = month;
		nam = year;
	}
	~CDate() { };
	CDate operator+ (int);
	CDate operator- (int);
	CDate operator++ (int);
	CDate operator-- (int);
	long operator- (const CDate&) const;
	friend istream& operator >> (istream& in, CDate& date);
	friend ostream& operator << (ostream& os, CDate& date);
};

