#include<iostream>
#include"DaThuc.h"
#include<cmath>
using namespace std;
DaThuc::DaThuc() {
    this->NumberOfElement = 0;
    this->x = new double[0 + 1];
    for (int i = 0; i <= this->NumberOfElement; i++) {
        this->x[i] = 0;
    }
}
DaThuc::DaThuc(int n) {
    this->NumberOfElement = n;
    this->x = new double[NumberOfElement + 1];
    for (int i = 0; i <= this->NumberOfElement; i++) {
        this->x[i] = 0;
    }
}
DaThuc::DaThuc(const DaThuc& DT) {
    this->NumberOfElement = DT.NumberOfElement;
    delete[] this->x;
    this->x = new double[NumberOfElement + 1];
    for (int i = 0; i <= this->NumberOfElement; i++) {
        this->x[i] = DT.x[i];
    }
}
DaThuc& DaThuc::operator=(const DaThuc& DT) {
    if (&DT == this) {
        return *this;
    }
    this->NumberOfElement = DT.NumberOfElement;
    delete[] this->x;
    this->x = new double[NumberOfElement + 1];
    for (int i = 0; i <= this->NumberOfElement; i++) {
        this->x[i] = DT.x[i];
    }
    return *this;
}
double DaThuc::GiaTriDaThuc(double* x, int NumberOfElement, double y)
{
    double result = 0.0;
    for (int i = 0; i <= NumberOfElement; i++) {
        result += x[i] * pow(y, i);
    }
    return result;
}
DaThuc operator+(const DaThuc& DT1, const DaThuc& DT2) {
    int max_num = 0;
    if (DT1.NumberOfElement > DT2.NumberOfElement) {
        max_num = DT1.NumberOfElement;
    }
    else {
        max_num = DT2.NumberOfElement;
    }
    DaThuc DT(max_num);
    for (int i = 0; i <= DT.NumberOfElement; i++) {
        if (i <= DT1.NumberOfElement && i <= DT2.NumberOfElement) {
            DT.x[i] = DT1.x[i] + DT2.x[i];
        }
        else {
            if (i > DT1.NumberOfElement) {
                DT.x[i] = DT2.x[i];
            }
            else if (i > DT2.NumberOfElement) {
                DT.x[i] = DT1.x[i];
            }
        }
    }
    return DT;
}
DaThuc operator-(const DaThuc& DT1, const DaThuc& DT2) {
    DaThuc DT((DT1.NumberOfElement > DT2.NumberOfElement) ? DT1.NumberOfElement : DT2.NumberOfElement);
    for (int i = 0; i <= DT.NumberOfElement; i++) {
        if (i <= DT1.NumberOfElement && i <= DT2.NumberOfElement) {
            DT.x[i] = DT1.x[i] - DT2.x[i];
        }
        else {
            if (i > DT1.NumberOfElement) {     //ngầm định DT1 - DT2
                DT.x[i] = -DT2.x[i];
            }
            else if (i > DT2.NumberOfElement) {
                DT.x[i] = DT1.x[i];
            }
            else {}
        }
    }
    return DT;
}
DaThuc operator*(const DaThuc& DT1, const DaThuc& DT2) {
    DaThuc DT(DT1.NumberOfElement + DT2.NumberOfElement);
    for (int i = 0; i <= DT1.NumberOfElement; i++) {
        for (int j = 0; j <= DT2.NumberOfElement; j++) {
            DT.x[i + j] += DT1.x[i] * DT2.x[j];
        }
    }
    return DT;
}
DaThuc operator/(const DaThuc& DT1, const DaThuc& DT2) {
    if (DT2.NumberOfElement == 0 && DT2.x[0] == 0) {
        cout << "Loi thuc hien phep chia 0" << endl;
        return DaThuc();
    }
    int max_num = DT1.NumberOfElement - DT2.NumberOfElement + 1;
    DaThuc DT(max_num);
    DaThuc tempDT1 = DT1;
    while (tempDT1.NumberOfElement >= DT2.NumberOfElement) {
        double ratio = tempDT1.x[tempDT1.NumberOfElement] / DT2.x[DT2.NumberOfElement];
        DT.x[tempDT1.NumberOfElement - DT2.NumberOfElement] = ratio;
        for (int i = 0; i <= DT2.NumberOfElement; i++) {
            tempDT1.x[tempDT1.NumberOfElement - DT2.NumberOfElement + i] -= DT2.x[i] * ratio;
        }
        tempDT1.NumberOfElement--;
    }

    return DT;
}
ostream& operator<<(ostream& os, DaThuc& DT) {
    for (int i = DT.NumberOfElement; i >= 0; i--) {
        if (DT.x[i] != 0) {
            if (DT.x[i] > 0) {
                if (i != DT.NumberOfElement && DT.PreAllZero(i) == 0) {
                    os << " + ";
                }
            }
            else {
                os << " - ";
            }
            if (abs(DT.x[i]) != 1) {
                os << abs(DT.x[i]);
            }
            if (i == 1) {
                os << "X";
            }
            else if (i == 0) {
            }
            else {
                os << "X^" << i;
            }
        }
    }
    return os;
}
istream& operator>>(istream& is, DaThuc& DT) {
    delete[] DT.x;
    cout << "Nhap bac cua da thuc: ";
    is >> DT.NumberOfElement;
    cout << "Nhap lan luot he so cua da thuc tu cao den thap: ";
    DT.x = new double[DT.NumberOfElement + 1];
    for (int i = DT.NumberOfElement; i >= 0; i--) {
        is >> DT.x[i];
    }
    return is;
}
DaThuc::~DaThuc() {
    delete[] this->x;
}
int main() {
    DaThuc DT1;
    DaThuc DT2;
    cout << "Nhap cac gia tri cua da thuc 1: " << endl;
    cin >> DT1;
    cout << DT1 << endl;
    cout << "Nhap cac gia tri cua da thuc 2: " << endl;
    cin >> DT2;
    cout << DT2 << endl;
    DaThuc AddDT = DT1 + DT2;
    cout << "Phep cong 2 da thuc: " << AddDT << endl;
    DaThuc SubDT = DT1 - DT2;
    cout << "Phep tru 2 da thuc: " << SubDT << endl;
    DaThuc MultiDT = DT1 * DT2;
    cout << "Phep nhan 2 da thuc: " << MultiDT << endl;
    DaThuc DivDT = DT1 / DT2;
    cout << "Phep chia 2 da thuc: " << DivDT << endl;
    
    double DT1x, DT2x;
    cout << "Nhap gia tri x cua da thuc 1: "; cin >> DT1x;
    cout << "Gia tri cua da thuc 1 tai x = " << DT1x << " : ";
    double result1 = DT1.GiaTriDaThuc(DT1.x, DT1.NumberOfElement, DT1x);
    cout << result1 << endl;
    cout << "Nhap gia tri x cua da thuc 2: "; cin >> DT2x;
    cout << "Gia tri cua da thuc 2 tai x = " << DT2x << " = ";
    double result2 = DT2.GiaTriDaThuc(DT2.x, DT2.NumberOfElement, DT2x);
    cout << result2 << endl;
    return 0;
}
