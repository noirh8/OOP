#include <iostream>
#include <cmath>
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
using namespace std;

istream& operator >> (istream& is, CDate& date)
{
	cout << "Nhap vao ngay thang nam" << endl;
	cout << "Nhap ngay: "; is >> date.ngay;
	cout << "Nhap thang: "; is >> date.thang;
	cout << "Nhap nam: "; is >> date.nam;
	return is;
}
ostream& operator << (ostream& os, CDate& date)
{
	os << date.ngay << "/" << date.thang << "/" << date.nam << endl;
	return os;
}
int CDate::NgayTrongThang(int thang, int nam) const
{
	int days;
	switch (thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		days = 31;
		break;
	case 4: case 6: case 9:  case 11:
		days = 30;
		break;
	case 2:
		if (nam % 400 == 0 || (nam % 100 != 0 && nam % 4 == 0))
			days = 29;
		else days = 28;
	default:
		days = 0;
		break;
	}
	return days;
}
CDate CDate::operator+(int days)
{
	CDate Date = *this;
	int totalDays = Date.ngay + days;
	while (totalDays > NgayTrongThang(Date.thang, Date.nam))
	{
		totalDays -= NgayTrongThang(Date.thang, Date.nam);
		Date.thang++;
		if (Date.thang > 12) {
			Date.thang = 1;
			Date.nam++;
		}
	}
	Date.ngay = totalDays;
	return Date;
}
CDate CDate::operator-(int days)
{
	CDate Date = *this;
	int totalDays = Date.ngay - days;
	if (totalDays < 1)
	{
		Date.thang--;
		if (Date.thang < 1) {
			Date.thang = 12;
			Date.nam--;
		}
		totalDays += NgayTrongThang(Date.thang, Date.nam);
	}
	Date.ngay = totalDays;
	return Date;
}
CDate CDate::operator++(int days)
{
	CDate Date = *this;
	int totalDays = Date.ngay + 1;
	while (totalDays > NgayTrongThang(Date.thang, Date.nam))
	{
		totalDays -= NgayTrongThang(Date.thang, Date.nam);
		Date.thang++;
		if (Date.thang > 12) {
			Date.thang = 1;
			Date.nam++;
		}
	}
	Date.ngay = totalDays;
	return Date;
}
CDate CDate::operator--(int days)
{
	CDate Date = *this;
	int totalDays = Date.ngay - 1;
	if (totalDays < 1)
	{
		Date.thang--;
		if (Date.thang < 1) {
			Date.thang = 12;
			Date.nam--;
		}
		totalDays += NgayTrongThang(Date.thang, Date.nam);
	}
	Date.ngay = totalDays;
	return Date;
}
long CDate::operator-(const CDate& other) const {
	int day_count = 0;
	for (int i = nam; i < other.nam; i++) {
		if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
			day_count += 366;
		}
		else {
			day_count += 365;
		}
	}
	int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 1; i < thang; i++) {
		day_count += days_in_month[i];
		if (i == 2 && (nam % 4 == 0 && (nam % 100 != 0 || nam % 400 == 0))) {
			day_count += 1;
		}
	}
	day_count += ngay - 1;
	// tính số ngày của năm other
	int days_in_month_other[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 1; i < other.thang; i++) {
		// tính số ngày từ ngày đầu tiên của năm other đến hết tháng trước đó
		day_count += days_in_month_other[i];
		if (i == 2 && (other.nam % 4 == 0 && (other.nam % 100 != 0 || other.nam % 400 == 0))) {
			day_count += 1;
		}
	}
	day_count += other.ngay - 1;
	return day_count;
}
int main()
{
	CDate Date;
	cin >> Date;
	cout << Date << endl;
	int addDay, subDay;
	CDate AddSomeDays, SubSomeDays, AddDay, SubDay;
	cout << "Nhap so ngay muon cong them: ";
	cin >> addDay;
	AddSomeDays = Date + addDay;
	cout << "Ngay thang nam sau khi cong them " << addDay << " ngay: " << AddSomeDays << endl;
	cout << "Nhap so ngay muon tru di: ";
	cin >> subDay;
	SubSomeDays = Date - subDay;
	cout << "Ngay thang nam sau khi tru di " << subDay << " ngay: " << SubSomeDays << endl;
	CDate ThemMotNgay;
	ThemMotNgay = Date++;
	cout << "Ngay thang nam sau khi them 1 ngay: " << ThemMotNgay;
	CDate TruMotNgay;
	TruMotNgay = Date--;
	cout << "Ngay thang nam sau khi tru 1 ngay: " << TruMotNgay << endl;
	CDate Date1;
	cout << "Nhap ngay can tinh khoang cach: " << endl;
	cin >> Date1;
	cout << Date1;
	cout << "Khoang cach: " << Date - Date1 << " ngay";
	return 0;
}
