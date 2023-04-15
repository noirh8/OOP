#include <iostream>
#include "CTimeSpan.h"
using namespace std;

int CTimeSpan::GetDay()
{
	return day;
}

int CTimeSpan::GetHour()
{
	return hour;
}

int CTimeSpan::GetMinute()
{
	return min;
}

int CTimeSpan::GetSecond()
{
	return sec;
}

long CTimeSpan::GetTotalSecond()
{
	return sec + min * 60 + hour * 3600 + day * 24 * 3600;
}
istream& operator >> (istream& is, CTimeSpan& time)
{
	cout << "Nhap ngay: "; is >> time.day;
	cout << "Nhap gio: "; is >> time.hour;
	cout << "Nhap phut: "; is >> time.min;
	cout << "Nhap giay: "; is >> time.sec;
	return is;
}
ostream& operator << (ostream& os, CTimeSpan& time)
{
	long totalSeconds = time.GetTotalSecond();
	int days = totalSeconds / 86400;
	int hours = (totalSeconds - days * 86400) / 3600;
	int minutes = (totalSeconds - days * 86400 - hours * 3600) / 60;
	int seconds = totalSeconds - days * 86400 - hours * 3600 - minutes * 60;
	if (days < 0 && hours < 0 && minutes < 0 && seconds < 0) {
		os << "INVALID TIME" << endl;
	}
	else os << days << "d:" << hours << "h:" << minutes << "m:" << seconds << "s" << endl;
	return os;
}
CTimeSpan CTimeSpan::operator+(const CTimeSpan& other)
{
	long totalSec = sec + other.sec
		+ 60 * (min + other.min)
		+ 60 * 60 * (hour + other.hour)
		+ 24 * 60 * 60 * (day + other.day);
	int days = totalSec / 86400;
	int hours = (totalSec - days * 86400) / 3600;
	int minutes = (totalSec - days * 86400 - hours * 3600) / 60;
	int seconds = totalSec - days * 86400 - hours * 3600 - minutes * 60;
	return CTimeSpan(days,hours, minutes, seconds);
}
CTimeSpan CTimeSpan::operator-(const CTimeSpan& other)
{
	long totalSec = other.sec - sec
		+ 60 * (other.min - min)
		+ 60 * 60 * (other.hour - hour)
		+ 24 * 60 * 60 * (other.day - day);
	int days = totalSec / 86400;
	int hours = (totalSec - days * 86400) / 3600;
	int minutes = (totalSec - days * 86400 - hours * 3600) / 60;
	int seconds = totalSec - days * 86400 - hours * 3600 - minutes * 60;
	return CTimeSpan(days, hours, minutes, seconds);
}
bool CTimeSpan::operator== (CTimeSpan& time)
{
	if (this->GetTotalSecond() == time.GetTotalSecond())
		return true;
	return false;
}
bool CTimeSpan::operator!= (CTimeSpan& time)
{
	if (this->GetTotalSecond() != time.GetTotalSecond())
		return true;
	return false;
}
bool CTimeSpan::operator> (CTimeSpan& time)
{
	if (this->GetTotalSecond() > time.GetTotalSecond())
		return true;
	return false;
}
bool CTimeSpan::operator>= (CTimeSpan& time)
{
	if (this->GetTotalSecond() >= time.GetTotalSecond())
		return true;
	return false;
}
bool CTimeSpan::operator< (CTimeSpan& time)
{
	if (this->GetTotalSecond() < time.GetTotalSecond())
		return true;
	return false;
}
bool CTimeSpan::operator<= (CTimeSpan& time)
{
	if (this->GetTotalSecond() <= time.GetTotalSecond())
		return true;
	return false;
}
int main()
{
	CTimeSpan time1, time2;
	cout << "Nhap thoi gian thu 1:"<< endl;
	cin >> time1;
	cout << time1 << endl;
	cout << "Nhap thoi gian thu 2:" << endl;
	cin >> time2;
	cout << time2 << endl;
	CTimeSpan time3,time4;
	time3 = time1 + time2;
	time4 = time1 - time2;
	cout << "Tong 2 CTimeSpan tren: " << time3 << endl;
	cout << "Hieu 2 CTimeSpan tren: " << time4 << endl;
	cout << "So sanh thoi gian 1 voi thoi gian 2" << endl;
	cout << "Bang nhau: "; 
		if (time1 == time2) cout << "true";
		else cout << "false";
		cout << endl;
	cout << "Khac nhau: ";
		if (time1 != time2) cout << "true";
		else cout << "false";
		cout << endl;
	cout << "Lon hon: ";
		if (time1 > time2) cout << "true";
		else cout << "false";
		cout << endl;
	cout << "Lon hon hoac bang: ";
		if (time1 >= time2) cout << "true";
		else cout << "false";
		cout << endl;
	cout << "Be hon: ";
		if (time1 < time2) cout << "true";
		else cout << "false";
		cout << endl;
	cout << "Be hon hoac bang: ";
		if (time1 <= time2) cout << "true";
		else cout << "false";
		cout << endl;
	cout << "Bang nhau: ";
		if (time1 == time2) cout << "true";
		else cout << "false";
		cout << endl;
}
