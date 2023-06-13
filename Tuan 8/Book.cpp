#include <iostream>
#include <string>
#include <limits>
#include <vector>
using namespace std;

class Book
{
private:
	string TenSach;
	string NXB;
	int NamXB;
	int SoTrang;
	double Gia;
public:
	Book() {
		SetTenSach("");
		SetNXB("");
		SetNamXB(0);
		SetPages(0);
		SetGia(0);
	}
	Book(const string ten, const string nxb, const int nam, const int pages, const double gia) {
		SetTenSach(ten);
		SetNXB(nxb);
		SetNamXB(nam);
		SetPages(pages);
		SetGia(gia);
	}
	~Book() { }
	void SetTenSach(string BookName) {
		TenSach = BookName;
	}
	void SetNXB(string nxb) {
		NXB = nxb;
	}
	void SetPages(int pages) {
		SoTrang = pages;
	}
	void SetNamXB(int nam) {
		NamXB = nam;
	}
	void SetGia(double gia) {
		Gia = gia;
	}
	void Nhap() {
		cin.ignore();
		string ten;
		cout << "Nhap ten sach: ";
		getline(cin, ten);
		SetTenSach(ten);
		cout << "Nhap ten nha xuat ban: ";
		string nxb;
		getline(cin, nxb);
		SetNXB(nxb);
		cout << "Nhap nam xuat ban: ";
		int namXB;
		cin >> namXB;
		SetNamXB(namXB);
		cout << "Nhap so trang: ";
		int soTrang;
		cin >> soTrang;
		cout << "Nhap gia: "; 
		double gia;
		cin >> gia;						
		SetGia(gia);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	string GetName() { return TenSach; }
	string GetNXB() { return NXB; }
	int GetNamXB() { return NamXB; }
	int GetPages() { return SoTrang; }
	double GetGia() { return Gia; }
	void Xuat() {
		cout << "Thong tin sach _____________________" << endl;
		cout << GetName() << endl;
		cout << "NXB: " << GetNXB() << endl;
		cout << "Nam xuat ban: " << GetNamXB() << endl;
		cout << "So trang:" << GetPages() << endl;
		cout << "Gia sach: " << GetGia() << endl;
	}
};

class SGK : public Book
{
private:
	int lop;
public: 
	SGK() {
		lop = 0;
	}
	SGK(int grade) {
		lop = grade;
	}
	~SGK() { }
	int GetLop() { return lop; }
	void SetLop(int grade) {
		lop = grade;
	}
	void Nhap() {
		int Lop;
		cout << "Khoi lop: "; cin >> Lop;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		SetLop(Lop);
		Book::Nhap();
	}
	void Xuat() {
		cout << "SGK lop " << GetLop() << endl;
		Book::Xuat();
	}
};
class Novel : public Book
{
private:
	string TheLoai;
public:
	Novel() {
		SetKind("");
	}
	Novel(const string kind) {
		SetKind(kind);
	}
	~Novel() { }
	void SetKind(string kind) {
		TheLoai = kind;
	}
	string GetKind() { return TheLoai; }
	void Nhap() {
		string kind;
		cout << "The loai: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, kind);
		SetKind(kind);
		Book::Nhap();
	}
	void Xuat() {
		cout << "The loai: " << GetKind();
		Book::Xuat();
	}
};
class TapChi : public Book
{
private:
	string ki;
public:
	TapChi() {
		SetKi("");
	}
	TapChi(string period) {
		SetKi(period);
	}
	~TapChi() { }
	void SetKi(string period) {
		ki = period;
	}
	string GetKi() { return ki; }
	void Nhap() {
		string period;
		cout << "Ki: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, period);
		SetKi(period);
		Book::Nhap();
	}
	void Xuat() {
		cout << "Ki cua tap chi: " << GetKi() << endl;
		Book::Xuat();
	}
};
void Input(vector<Book*>& List) {
	int CatchKind;
	do {
		cout << "Chon the loai sach: \n";
		cout << "1.SGK  2.Novel  3.Tap chi  4.Quaylai\n";
		while (cin >> CatchKind && CatchKind != 1 && CatchKind != 2 && CatchKind != 3 && CatchKind != 4) {
			cout << "Chon sai. Vui long chon lai" << endl;
		}
		switch (CatchKind)
		{
		case 1:
			List.push_back(new SGK);
			List[List.size() - 1]->Nhap();
			break;
		case 2:
			List.push_back(new Novel);
			List[List.size() - 1]->Nhap();
			break;
		case 3:
			List.push_back(new TapChi);
			List[List.size() - 1]->Nhap();
		default:
			break;
		}
	} while (CatchKind != 4);
}
void PrintList(vector<Book*>& List) {
	cout << "-----Xuat danh sach cac loai sach----\n";
	for (int i = 0; i < List.size(); i++) {
		cout << " - ";
		List[i]->Xuat();
		cout << endl;
	}
	cout << "------------------------------\n";
}
int main() {
	vector<Book*> ListBook;
	ListBook.resize(0);
	int CatchKey;
	do {
		cout << "Quan li sach: \n";
		cout << "1. Nhap  2. Xuat  3. Thoat\n";
		cin >> CatchKey;
		while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3) {
			cout << "Chon sai. Vui long chon lai" << endl;
		}
		switch (CatchKey)
		{
		case 1:
			Input(ListBook);
			break;
		case 2:
			PrintList(ListBook);
			break;
		default:
			break;
		}
	} while (CatchKey != 3);
	return 0;
}
