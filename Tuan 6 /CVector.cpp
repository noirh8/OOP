#include <iostream>
#include <vector>
using namespace std;

class CVector
{
private:
	vector<double> vt;
	int dai;
public:
	CVector() {
		int n = 0;
	}
	CVector(int n) {
		vt.resize(n);
		dai = n;
		for (int i = 0; i < dai; i++) {
			vt[i] = 0;
		}
	}
	~CVector() { }
	CVector operator + (CVector& vt) {
		if (this->dai != vt.dai) {
			cout << "2 vecto khac so chieu" << endl;
			return *this;
		}
		CVector other;
		other = *this;
		for (int i = 0; i < dai; i++) {
			other.vt[i] += vt.vt[i];
		}
		return other;
	}
	CVector operator - (CVector& vt) {
		if (this->dai != vt.dai) {
			cout << "2 vecto khac so chieu" << endl;
			return *this;
		}
		CVector other;
		other = *this;
		for (int i = 0; i < dai; i++) {
			other.vt[i] -= vt.vt[i];
		}
		return other;
	}
	CVector operator * (CVector& vt) {
		if (this->dai != vt.dai) {
			cout << "2 vecto khac so chieu" << endl;
			return *this;
		}
		CVector other;
		other = *this;
		for (int i = 0; i < dai; i++) {
			other.vt[i] *= vt.vt[i];
		}
		return other;
	}
	CVector operator * (const int k) {
		CVector other;
		other = *this;
		for (int i = 0; i < dai; i++) {
			other.vt[i] *= k;
		}
		return other;
	}
	friend istream& operator >> (istream& is, CVector& vt) {
		cout << "Nhap so chieu: "; is >> vt.dai;
		vt.vt.resize(vt.dai);
		cout << "Nhap cac phan tu" << endl;
		for (int i = 0; i < vt.dai; i++) {
			is >> vt.vt[i];
		}
		return is;
	}
	friend ostream& operator << (ostream& os, CVector& vt) {
		os << "(";
		for (int i = 0; i < vt.dai; i++) {
			if (i != vt.dai - 1) os << vt.vt[i] << ", ";
			else os << vt.vt[i];
		}
		os << ")" << endl;
		return os;
	}
	double operator [] (int i) {
		return vt[i];
	}
	int getDai() {
		return dai;
	}
};
class CMatrix
{
private:
	vector <vector <double> > vt;
	int hang, cot;
public:
	CMatrix() {
		hang = cot = 0;
	}
	CMatrix(int m, int n) {
		hang = m;
		cot = n;
		vt.resize(hang);
		for (int i = 0; i < hang; i++) {
			vt.resize(cot);
			for (int j = 0; j < cot; j++) {
				vt[i][j] = 0;
			}
		}
	}
	~CMatrix() { }
	CMatrix operator + (const CMatrix mt) {
		if (hang != mt.hang || cot != mt.cot) {
			cout << "2 ma tran khac nhau" << endl;
			return *this;
		}
		CMatrix other;
		other = *this;
		for (int i = 0; i < hang; i++) {
			for (int j = 0; j < cot; j++) {
				other.vt[i][j] += mt.vt[i][j];
			}
		}
		return other;
	}
	CMatrix operator - (const CMatrix mt) {
		if (hang != mt.hang || cot != mt.cot) {
			cout << "2 ma tran khac nhau" << endl;
			return *this;
		}
		CMatrix other;
		other = *this;
		for (int i = 0; i < hang; i++) {
			for (int j = 0; j < cot; j++) {
				other.vt[i][j] -= mt.vt[i][j];
			}
		}
		return other;
	}
	CMatrix operator * (const CMatrix mt) {
		if (cot != mt.hang) {
			cout << "Khong the thuc hien phep nhan" << endl;
			return *this;
		}
		CMatrix other(hang, mt.cot);
		for (int i = 0; i < hang; i++) {
			for (int j = 0; j < mt.cot; j++) {
				for (int k = 0; k < cot; k++) {
					other.vt[i][j] += this->vt[i][k] * mt.vt[k][j];
				}
			}
		}
		return other;
	}
	CMatrix operator * (const int k) {
		for (int i = 0; i < hang; i++) {
			for (int j = 0; j < cot; j++) {
				this->vt[i][j] *= k;
			}
		}
		return *this;
	}
	CMatrix operator * (CVector& vt) {
		CMatrix other(1, vt.getDai());
		for (int i = 0; i < other.cot; i++) {
			other.vt[0][i] = vt[i];
		}
		return (*this) * other;
	}
	friend istream& operator >> (istream& is, CMatrix& mt) {
		cout << "Nhap so hang so cot cua ma tran: ";
		cin >> mt.hang >> mt.cot;
		mt.vt.resize(mt.hang);
		for (int i = 0; i < mt.hang; i++) {
			mt.vt[i].resize(mt.cot);
			for (int j = 0; j < mt.cot; j++) {
				is >> mt.vt[i][j];
			}
		}
		return is;
	}
	friend ostream& operator << (ostream& os, CMatrix& mt) {
		for (int i = 0; i < mt.hang; i++) {
			for (int j = 0; j < mt.cot; j++) {
				os << mt.vt[i][j] << "  ";
			}
			os << endl;
		}
		return os;
	}
};
int main()
{
	cout << "Vector _____________" << endl;
	CVector vt1, vt2;
	cout << "Nhap vecto thu nhat: " << endl; cin >> vt1;
	cout << "Nhap vecto thu hai: " << endl; cin >> vt2;
	cout << "Vector 1: " << vt1 ;
	cout << "Vector 2: " << vt2 ;
	cout << endl;
	CVector sum, sub, multi, multiwK1, multiwK2;
	sum = vt1 + vt2;
	cout << "VT1 + VT2 = " << sum;
	sub = vt1 - vt2; 
	cout << "VT1 - VT2 = " << sub;
	multi = vt1 * vt2;
	cout << "VT1 * VT2 = " << multi;
	int k;
	cout << "Nhap so nguyen k muon nhan voi ma tran: ";
	cin >> k;
	multiwK1 = vt1 * k;
	multiwK2 = vt2 * k;
	cout << k << " * VT1 = " << multiwK1;
	cout << k << " * VT2 = " << multiwK2;
	cout << endl;
	cout << "Ma tran ___________________" << endl;
	CMatrix mt1, mt2;
	cout << "Nhap vao ma tran thu nhat " << endl;
	cin >> mt1;
	cout << "Nhap vao ma tran thu hai " << endl;
	cin >> mt2;
	cout << "Ma tran 1: " << endl;
	cout << mt1;
	cout << "Ma tran 2: " << endl;
	cout << mt2;
	CMatrix sumMT, subMT, multiMT, multiMTK1, multiMTK2;
	sumMT = mt1 + mt2;
	subMT = mt1 - mt2;
	multiMT = mt1 * mt2;
	cout << "MT1 + MT2 = " << sumMT;
	cout << "MT1 - MT2 = " << subMT;
	cout << "MT1 * MT2 = " << multiMT;
	int m;
	cout << "Nhap so nguyen de nhan ma tran: "; cin >> m;
	multiMTK1 = mt1 * m;
	multiMTK2 = mt2 * m;
	cout << m << " * MT1 = " << multiMTK1;
	cout << m << " * MT2 = " << multiMTK2;
	return 0;
}
