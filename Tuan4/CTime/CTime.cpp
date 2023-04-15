#include <iostream>
#include "CTime.h"
using namespace std;

int CTime::GetHour()
{
	return hour;
}

int CTime::GetMinute()
{
	return min;
}

int CTime::GetSecond()
{
	return sec;
}
long CTime::GetTotalSecond()
{
	return sec + min * 60 + hour * 60 * 60;
}
CTime CTime::operator+(int& giay)
{
	CTime temp;
	temp.hour = this->hour;
	temp.min = this->min;
	temp.sec = this->sec;
	temp.sec += giay;
	return temp;
}

CTime CTime::operator-(int& giay)
{
	CTime temp;
	temp.hour = this->hour;
	temp.min = this->min;
	temp.sec = this->sec;
	temp.sec -= giay;
	return temp;
}

CTime CTime::operator-(CTime& TG)
{
	CTime Time;
	Time.hour = hour - TG.hour;
	Time.min = min - TG.min;
	Time.sec = sec - TG.sec;
	return Time;

}
CTime CTime::operator++(int giay)
{
	CTime temp;
	temp.hour = this->hour;
	temp.min = this->min;
	temp.sec = this->sec;
	temp.sec++;
	return temp;
}
CTime CTime::operator--(int giay)
{
	CTime temp;
	temp.hour = this->hour;
	temp.min = this->min;
	temp.sec = this->sec;
	temp.sec--;
	return temp;
}
istream& operator >> (istream& is, CTime& time)
{
	cout << "Nhap gio: "; is >> time.hour;
	cout << "Nhap phut: "; is >> time.min;
	cout << "Nhap giay: "; is >> time.sec;
	return is;
}
ostream& operator << (ostream& os, CTime& time)
{
	int totalSeconds = time.GetTotalSecond();
	int hours = totalSeconds / 3600;
	int minutes = (totalSeconds - hours * 3600) / 60;
	int seconds = totalSeconds - hours * 3600 - minutes * 60;
	os << hours << "h:" << minutes << "m:" << seconds << "s" << endl;
	return os;
}
int main()
{
	CTime time;
	cout << "Nhap thoi gian: " << endl;
	cin >> time;
	cout << time << endl;
	int addSec;
	cout << "Nhap so giay muon cong them: ";
	cin >> addSec;
	CTime Add = time + addSec;
	cout << "Thoi gian sau khi cong them " << addSec << " giay: " << Add << endl;
	int subSec;
	cout << "Nhap so giay muon tru di: ";
	cin >> subSec;
	CTime Sub = time - subSec;
	cout << "Thoi gian sau khi tru di " << subSec << " giay: " << Sub << endl;
	
	CTime Subtime;
	cout << "Nhap thoi gian muon tru: " << endl;
	cin >> Subtime;
	cout << Subtime;
	CTime CTimeSpan = time - Subtime;
	cout << "Khoang thoi gian sau khi tru: ";
	cout << CTimeSpan << endl;

	CTime ThemGiay = time++;
	cout << "Thoi gian sau khi tang 1 giay: "; 
	cout << ThemGiay << endl;
	CTime TruGiay = time--;
	cout << "Thoi gian sau khi tru 1 giay: ";
	cout << TruGiay << endl;
}
