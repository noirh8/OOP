#include <iostream>
using namespace std;
// Hàm kiểm tra năm nhuận
bool LeapYear(int Year)
{
	if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
	{
		return true;
	}
	return false;
}

// Hàm cho số ngày trong tháng
int DaysOfMonth(int Month, int Year)
{
	int Days;
	switch (Month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		Days = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		Days = 30;
		break;
	case 2:
		if (LeapYear(Year)){
			Days = 29;
		}
		else{
			Days = 28;
		}
		break;
	}

	return Days;
}

// Hàm kiểm tra hợp lệ
bool ValidDays(int Day, int Month, int Year)
{
	bool valid = true;

	if (!(Year > 0 && Month))
	{
		valid = false;
	}
	if (!(Month >= 1 && Month <= 12))
	{
		valid = false;
	}
	if (!(Day >= 1 && Day <= DaysOfMonth(Month, Year)))
	{
		valid = false;
	}
	return valid;
}
void FindNextDay(int& Day, int& Month, int& Year)
{
	Day++;
	if (Day > DaysOfMonth(Month, Year))
	{
		Day = 1;
		Month++;
		if (Month > 12)
		{
			Month = 1;
			Year++;
		}
	}
}
int main()
{
	int Day, Month, Year;
	cout << "Day: ";	cin >> Day;
	cout << "Month: ";	cin >> Month;
	cout << "Year: ";	cin >> Year;

	if (ValidDays(Day, Month, Year))
	{
        int tmpDay = Day;
		int tmpMonth = Month;
		int tmpYear = Year;
		FindNextDay(tmpDay, tmpMonth, tmpYear);
		cout << "Next day: " << tmpDay << " / " << tmpMonth << " / " << tmpYear << endl;
	}
	else
	{
		cout << "Invalid day" << endl;
	}

	return 0;
}

