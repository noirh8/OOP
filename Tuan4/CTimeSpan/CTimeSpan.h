#pragma once
using namespace std;
class CTimeSpan
{
private:
	int day;
	int hour, min, sec;
public:
	CTimeSpan(int ngay =0, int gio = 0, int phut = 0, int giay = 0)
	{
		day = ngay;
		hour = gio;
		min = phut;
		sec = giay;
	}
	~CTimeSpan() { }
	int GetDay();
	int GetHour();
	int GetMinute();
	int GetSecond();
	long GetTotalSecond();
	CTimeSpan operator+(const CTimeSpan& time);
	CTimeSpan operator-(const CTimeSpan& time);
	bool operator ==  (CTimeSpan&);
	bool operator != (CTimeSpan&);
	bool operator > (CTimeSpan&);
	bool operator >= (CTimeSpan&);
	bool operator < (CTimeSpan&);
	bool operator <= (CTimeSpan&);
	friend istream& operator >> (istream& is, CTimeSpan& time);
	friend ostream& operator << (ostream& os, CTimeSpan& time);
};
