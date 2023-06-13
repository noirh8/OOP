#include <iostream>
using namespace std;
class Person
{
private:
	char HoTen[100];
	int ngay, thang, nam;
	char NoiO[100];
	int GioiTinh;
public:
	Person() { }
	~Person() { }
	virtual void Nhap() {
		cout << "____________________________________________________" << endl;
		cout << "Nhap vao thong tin" << endl;
		cout << "Nhap vao ho ten: "; cin >> HoTen;
		cout << "Nhap vao ngay thang nam sinh: "; 
		cin >> ngay >> thang >> nam;
		cout << "Nhap noi o: "; cin >> NoiO;
		GioiTinh = 0;
		do {
			cout << "Gioi tinh (1.NAM  2.NU)" << endl;
			cout << "Nhap lua chon: "; cin >> GioiTinh;
			if (GioiTinh != 1 && GioiTinh != 2)
				cout << "Lua chon khong hop le! Vui long chon lai";
		} while (GioiTinh != 1 && GioiTinh != 2);
	}
	virtual void Xuat() {
		cout << "____________________________________________________" << endl;
		cout << "Thong tin da nhap" << endl;
		cout << "Ho ten: " << HoTen << endl;
		cout << "Gioi tinh: ";
		if (GioiTinh == 1) cout << "NAM" << endl;
		else if (GioiTinh == 2) cout << "NU" << endl;
		cout << "Ngay thang nam sinh: " << ngay << "/" << thang << "/" << nam << endl;
		cout << "Noi o: " << NoiO << endl;
	}
};
class SinhVien : virtual public Person
{
private:
	int NamHoc, NienKhoa;
	char TenTruong[100], Nganh[100];
public:
	SinhVien() { }
	~SinhVien() { }
	virtual void Nhap() {
		Person::Nhap();
		cout << "Sinh vien nam thu "; cin >> NamHoc;
		cout << "Nien khoa "; cin >> NienKhoa;
		cout << "Ten truong: "; cin >> TenTruong;
		cout << "Ten nganh: "; cin >> Nganh;
	}
	virtual void Xuat() {
		Person::Xuat();
		cout << "Sinh vien nam thu " << NamHoc << endl;
		cout << "Nien khoa " << NienKhoa << endl;
		cout << "Thuoc truong " << TenTruong << endl;
		cout << "Nganh hoc: " << Nganh << endl;
	}
};
class HocSinh : virtual public Person
{
private: 
	char Truong[100];
	char Lop[100];
public:
	HocSinh() { }
	~HocSinh() { }
	virtual void Nhap() {
		Person::Nhap();
		cout << "Ten truong: "; cin >> Truong;
		cout << "Lop: "; cin >> Lop;
	}
	virtual void Xuat() {
		Person::Xuat();
		cout << "Hoc sinh truong " << Truong << endl;
		cout << "Lop " << Lop << endl;
	}
};
class CongNhan : virtual public Person
{
private:
	char NoiLamViec[100];
	long Luong;
public:
	CongNhan() { }
	~CongNhan() { }
	virtual void Nhap() {
		Person::Nhap();
		cout << "Nhap noi lam viec: "; cin >> NoiLamViec;
		cout << "Nhap luong: "; cin >> Luong;
	}
	virtual void Xuat() {
		Person::Xuat();
		cout << "Noi lam viec: " << NoiLamViec << endl;
		cout << "Luong: " << Luong << endl;
	}
};
class NS : virtual public Person
{
private:
	char NgheDanh[100];
	char ChuyenMon[100];
public:
	NS() { }
	~NS() { }
	virtual void Nhap() {
		Person::Nhap();
		cout << "Nghe danh cua nghe si: "; cin >> NgheDanh;
		cout << "Chuyen mon cua nghe si: "; cin >> ChuyenMon;
	}
	virtual void Xuat() {
		Person::Xuat();
		cout << "Nghe danh: " << NgheDanh << endl;
		cout << "Linh vuc chuyen mon: " << ChuyenMon << endl;
	}
};
class CS : virtual public Person
{
private:
	char NgheDanh[100];
	char ChuyenMon[100];
public:	
	CS() { }
	~CS() { }
	virtual void Nhap() {
		Person::Nhap();
		cout << "Nghe danh cua ca si: "; cin >> NgheDanh;
		cout << "Chuyen mon cua ca si: "; cin >> ChuyenMon;
	}
	virtual void Xuat() {
		Person::Xuat();
		cout << "Nghe danh: " << NgheDanh << endl;
		cout << "Linh vuc chuyen mon: " << ChuyenMon << endl;
	}
};
class QLNN : public Person
{
private:
	Person** DuLieu;
	int SoNguoi;
public:
	QLNN() {
		SoNguoi = 0;
		DuLieu = new Person * [SoNguoi];	
	}
	~QLNN() {
		delete[] DuLieu;
	}
	void Nhap() {
		cout << "Nhap so nguoi can quan li: ";
		cin >> SoNguoi;
		int LuaChon = 0;
		for (int i = 0; i < SoNguoi; i++) {
			do {
				cout << "________________________________________________________" << endl;
				cout << "Nhap vao thong tin nguoi thu " << i+1 << endl;
				cout << "1.Sinh vien    2.Hoc sinh" << endl;
				cout << "3.Cong nhan    3.Nghe si" << endl;
				cout << "5.Ca si" << endl;
				cout << "Nhap vao lua chon: "; cin >> LuaChon;
				if (LuaChon != 1 && LuaChon != 2 && LuaChon != 3 && LuaChon != 4 && LuaChon != 5)
					cout << "Lua chon sai! Vui long chon lai" << endl;
			} while (LuaChon != 1 && LuaChon != 2 && LuaChon != 3 && LuaChon != 4 && LuaChon != 5);
			if (LuaChon == 1) DuLieu[i] = new SinhVien;
			else if (LuaChon == 2) DuLieu[i] = new HocSinh;
			else if (LuaChon == 3) DuLieu[i] = new CongNhan;
			else if (LuaChon == 4) DuLieu[i] = new NS;
			else if (LuaChon == 5) DuLieu[i] = new CS;
			DuLieu[i]->Nhap();
		}
	}
	void Xuat() {
		cout << "________________________________________________________________________" << endl;
		for (int i = 0; i < SoNguoi; i++) {
			cout << endl;
			cout << "Thong tin cua nguoi thu " << i + 1 << endl;
			DuLieu[i]->Xuat();
		}
	}
};
int main()
{
	QLNN a1;
	a1.Nhap();
	a1.Xuat();
	return 0;
}
