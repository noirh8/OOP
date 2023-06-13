#include <iostream>
#include <string>
using namespace std;

struct DateNV {
	int Ngay, Thang, Nam;
};
class NhanVien
{
private:
	string HoTen;
	DateNV Date;
public:
	NhanVien() {};
	int SoNgayLam;
	void Nhap() {
		cout << "Nhap ho ten: ";
		cin.ignore();
		getline(cin, HoTen);
		cout << "Nhap ngay thang nam sinh: " << endl;
		cout << "Nhap ngay: "; cin >> Date.Ngay;
		cout << "Nhap thang: "; cin >> Date.Thang;
		cout << "Nhap nam: "; cin >> Date.Nam;
	}
	void Xuat() {
		cout << "Ho va ten nhan vien: " << HoTen << endl;
		cout << "Sinh ngay " << Date.Ngay << "/" << Date.Thang << "/" << Date.Nam << endl;
	}
	long int TinhLuong() { return 0; }
	~NhanVien() {};
};
class NVVP : public NhanVien {
private:
	int snlv;
public:
	NVVP() {};
	~NVVP() {};
	void Nhap() {
		NhanVien::Nhap();
		cout << "Nhap so ngay lam viec: "; cin >> snlv;
	}
	void Xuat() {
		NhanVien::Xuat();
		cout << "So ngay lam viec: "; cout << snlv << endl;
	}
	long int Luong() {
		return snlv * 100000;
	}
};
class NVSX : public NhanVien {
private:
	int LuongCoBan, SoSanPham;
public:
	NVSX() { }
	~NVSX() { }
	void Nhap() {
		NhanVien::Nhap();
		cout << "Nhap luong co ban: "; cin >> LuongCoBan;
		cout << "Nhap so san pham: "; cin >> SoSanPham;
	}
	void Xuat() {
		NhanVien::Xuat();
		cout << "Co luong co ban: " << LuongCoBan << endl;
		cout << "Tong so san phan lam duoc: " << SoSanPham << endl;
	}
	long int Luong() {
		return LuongCoBan + (SoSanPham * 5000);
	}
};
class QLNV
{
private:
	NhanVien** DuLieu;
	long SoLuongNhanVien;
	long TongLuongPhaiTra;
public:
	QLNV() {
		SoLuongNhanVien = 0;
		DuLieu = new NhanVien * [SoLuongNhanVien];
		TongLuongPhaiTra = 0;
	}
	~QLNV() {
		delete[]DuLieu;
	}
	void Nhap() {
		cout << "Nhap so luong nhan vien: "; cin >> SoLuongNhanVien;
		int LuaChon = 0;
		for (int i = 0; i < SoLuongNhanVien; i++) {
			do {
				cout << endl;
				cout << "Nhap thong tin nhan vien thu " << i + 1 << ": " << endl;
				cout << "(1. Nhan vien san xuat		2. Nhan vien van phong)" << endl << endl;
				cout << "Nhap lua chon: "; cin >> LuaChon;
				if (LuaChon != 1 && LuaChon != 2) cout << "Lua chon sai! Vui long chon lai";
			} while (LuaChon != 1 && LuaChon != 2);
			if (LuaChon == 1) {
				cout << "Nhan vien San Xuat" << endl;
				DuLieu[i] = new NVSX;
			}
			if (LuaChon == 2) {
				cout << "Nhan vien Van Phong" << endl;
				DuLieu[i] = new NVVP;
			}
			DuLieu[i]->Nhap();
			TongLuongPhaiTra += DuLieu[i]->TinhLuong();
		}
	}
	void Xuat() {
		cout << "Tong so nhan vien cua cong ty: " << SoLuongNhanVien << endl;
		for (int i = 0; i < SoLuongNhanVien; i++) {
			cout << endl;
			cout << "Thong tin nhan vien thu " << i + 1 << ": " << endl;
			DuLieu[i]->Xuat();
			cout << "Tien luong nhan duoc: " << DuLieu[i]->TinhLuong();
		}
		cout << endl;
		cout << "Tong so luong ma cong ty phai tra cho nhan vien: " << TongLuongPhaiTra << endl;
	}
};


int main()
{
	QLNV NV;
	NV.Nhap();
	NV.Xuat();
}
