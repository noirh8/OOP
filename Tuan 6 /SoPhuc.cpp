#include <iostream>
#include <math.h>
using namespace std;

class SoPhuc
{
private:
	double thuc, ao;
public:
	SoPhuc(double Thuc = 0, double  Ao = 0) {
		thuc = Thuc;
		ao = Ao;
	}
	SoPhuc(double t) {
		thuc = t;
		ao = 0;
	}
	~SoPhuc() { }
	friend istream& operator >> (istream& is, SoPhuc& a);
	friend ostream& operator << (ostream& os, SoPhuc& a);
	SoPhuc operator + (SoPhuc& a) {
		SoPhuc temp;
		temp.thuc = this->thuc + a.thuc;
		temp.ao = this->ao + a.ao;
		return temp;
	}
	SoPhuc operator - (SoPhuc& a) {
		SoPhuc temp;
		temp.thuc = this->thuc - a.thuc;
		temp.ao = this->ao - a.ao;
		return temp;
	}
	SoPhuc operator * (SoPhuc& a) {
		SoPhuc temp;
		temp.thuc = (this->thuc * a.thuc) - (this->ao * a.ao);
		temp.ao = (this->thuc * a.ao) + (this->ao * a.thuc);
		return temp;
	}
	SoPhuc operator / (SoPhuc& a) {
		SoPhuc temp;
		temp.thuc = (this->thuc * a.thuc + this->ao * a.ao) / (pow(a.thuc, 2) + pow(a.ao, 2));
		temp.ao = (this->thuc * a.ao + this->ao * a.thuc) / (pow(a.thuc, 2) + pow(a.ao, 2));
		return temp;
	}
	bool operator == (SoPhuc& a) {
		if (this->thuc == a.thuc && this->ao == a.ao)
			return true;
		return false;
	}
	bool operator != (SoPhuc& a) {
		if (this->thuc != a.thuc && this->ao != a.ao)
			return true;
		return false;
	}
};

istream& operator >> (istream& is, SoPhuc& a) {
	cout << "Nhap so phuc: " << endl;
	cout << "Phan thuc: "; is >> a.thuc;
	cout << "Phan ao: "; is >> a.ao;
	return is;
}
ostream& operator << (ostream& os, SoPhuc& a) {
	os << a.thuc;
	if (a.ao >= 0) os << " + " << a.ao << "i" << endl;
	else os << a.ao << "i" << endl;
	return os;
}
int main()
{
	SoPhuc s1, s2;
	cin >> s1 >> s2;
	cout << "So phuc thu nhat: " << s1 << endl;
	cout << "So phuc thu hai: " << s2 << endl;
	SoPhuc cong, tru, nhan, chia;
	cong = s1 + s2;
	cout << "Tong 2 so phuc: " << cong;
	tru = s1 - s2;
	cout << "Hieu 2 so phuc: " << tru;
	nhan = s1 * s2;
	cout << "Tich 2 so phuc: " << nhan;
	chia = s1 / s2;
	cout << "Thuong 2 so phuc: " << chia;
	cout << endl;
	cout << "So sanh 2 so phuc: " << endl;
	cout << "2 so phuc == : ";
	if (s1 == s2) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;
	cout << "2 so phuc != : ";
	if (s1 != s2) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;
	return 0;
}
