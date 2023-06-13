#include <iostream>
#include <cmath>
#include<vector>
using namespace std;
struct Diem {
    double x;
    double y;
};
class TuGiac
{
private:
    Diem diem[4];
public:
    TuGiac() {
        Diem c[4];
        for (int i = 0; i < 4; i++) {
            c[i].x = c[i].y = 0;
        }
        SetDiem(c);
    }
    TuGiac(Diem* d) {
        SetDiem(d);
    }
    virtual ~TuGiac() { }

    void SetDiem(Diem c[4]) {
        for (int i = 0; i < 4; i++) {
            diem[i].x = c[i].x;
            diem[i].y = c[i].y;
        }
    }
    virtual void Set() {
        Diem c[4];
        do {
            for (int i = 0; i < 4; i++) {
                cout << "Diem thu " << i + 1 << " (x,y): ";
                cin >> c[i].x >> c[i].y;
            }
            SetDiem(c);
        } while (this->Check() == 0);
    }

    Diem* GetDiem() { return diem; }

    virtual bool Check() = 0;
    virtual void Xuat() {
        Diem* c = GetDiem();
        for (int i = 0; i < 4; i++) {
            cout << "( " << c[i].x << " , " << c[i].y << ")";
            if (i != 3) {
                cout << "--";
            }
        }
    }
};
//other
double MultiCoor(Diem c1, Diem c2) {
    return c1.x * c2.x + c1.y * c2.y;
}
double Module(Diem c1, Diem c2) {
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}
Diem VectorCoor(Diem c1, Diem c2) {
    Diem c;
    c.x = c1.x - c2.x;
    c.y = c1.y - c2.y;
    return c;
}

class HinhThang :public TuGiac
{
private:
    double dai;
    double ngan;
    double cao;
public:
    HinhThang() {
        SetDai(0);
        SetNgan(0);
        SetCao(0);
    }
    HinhThang(double d, double n, double c) {
        SetDai(d);
        SetNgan(n);
        SetCao(c);
    }
    ~HinhThang() { }

    void Set() {
        cout << "Nhap hinh thang " << endl;
        TuGiac::Set();
    }
    void SetDai(double d) {
        dai = d;
    }
    void SetNgan(double n) {
        ngan = n;
    }
    void SetCao(double c) {
        cao = c;
    }

    double GetDai() { return dai; }
    double GetNgan() { return ngan; }
    double GetCao() { return cao; }

    virtual bool Check() {
        Diem YAxis = { 0,1 };
        Diem* c = GetDiem();
        vector<double> value;
        double h;
        value.resize(0);
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (MultiCoor(VectorCoor(c[i], c[j]), YAxis) == 0) {
                    value.push_back(Module(c[i], c[j]));
                    for (int k = 0; k < 4; k++) {
                        if (k != i && k != j) {
                            h = abs(c[k].y - c[i].y);
                        }
                    }
                }
            }
        }
        if (value.size() != 2) {
            cout << "Wrong input!\n";
            return false;
        }
        else {
            SetDai(value[0] > value[1] ? value[0] : value[1]);
            SetNgan(value[0] < value[1] ? value[0] : value[1]);
            SetCao(h);
            return true;
        }
    }
    void Xuat() {
        cout << "Hinh thang: \n";
        TuGiac::Xuat();
        cout << "\n\t-Canh Dai: " << GetDai() << endl;
        cout << "\n\t-Canh Ngan: " << GetNgan() << endl;
        cout << "\n\t-Chieu Cao: " << GetCao() << endl;
    }
};

class HinhBinhHanh :public TuGiac
{
private:
    double dai;
    double ngan;
    double cao;
public:
    HinhBinhHanh() {
        SetDai(0);
        SetNgan(0);
        SetCao(0);
    }
    HinhBinhHanh(double d, double n, double c) {
        SetDai(d);
        SetNgan(n);
        SetCao(c);
    }
    ~HinhBinhHanh() { }
    
    void Set() {
        cout << "Nhap hinh binh hanh" << endl;
        TuGiac::Set();
    }
    void SetDai(double d) {
        dai = d;
    }
    void SetNgan(double n) {
        ngan = n;
    }
    void SetCao(double c) {
        cao = c;
    }
    
    double GetDai() { return dai; }
    double GetNgan() { return ngan; }
    double GetCao() { return cao; }
    
    virtual bool Check() {
        Diem YAxis = { 0,1 };
        Diem* c = GetDiem();
        vector<double> value;
        double h;
        double s;
        value.resize(0);

        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (MultiCoor(VectorCoor(c[i], c[j]), YAxis) == 0) {
                    value.push_back(Module(c[i], c[j]));
                    for (int k = 0; k < 4; k++) {
                        if (k != i && k != j) {
                            h = abs(c[k].y - c[i].y);
                            double d1 = Module(c[k], c[i]);
                            double d2 = Module(c[k], c[j]);
                            s = (d1 < d2 ? d1 : d2);
                        }
                    }
                }

            }
        }
        if (value.size() == 2 && value[0] == value[1]) {
            SetDai(value[0] > s ? value[0] : s);
            SetNgan(value[0] < s ? value[0] : s);
            SetCao(h);
            return true;
        }
        else {
            cout << "Wrong input!\n";
            return false;
        }
    }
    void Xuat() {
        cout << "Hinh binh hanh: \n";
        TuGiac::Xuat();
        cout << "\n\t-Canh dai: " << GetDai() << endl;
        cout << "\n\t-Canh ngan: " << GetNgan() << endl;
        cout << "\n\t-Chieu cao: " << GetCao() << endl;
    }
};

class HCN :public TuGiac
{
private:
    double rong;
    double dai;
public:
    HCN() {
        SetRong(0);
        SetDai(0);
    }
    HCN(double r, double d) {
        SetRong(r);
        SetDai(d);
    }
    ~HCN() { }
    //Setter
    void Set() {
        cout << "Nhap hinh chu nhat" << endl;
        TuGiac::Set();
    }
    void SetRong(double r) {
        rong = r;
    }
    void SetDai(double d) {
        dai = d;
     }
    
    double GetRong() { return rong; }
    double GetDai() { return dai; }
    
    virtual bool Check() {
        Diem YAxis = { 0,1 };
        Diem XAxis = { 1,0 };
        Diem* c = GetDiem();
        vector<double> Xvalue;
        vector<double> Yvalue;
        Xvalue.resize(0);
        Yvalue.resize(0);
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (MultiCoor(VectorCoor(c[i], c[j]), YAxis) == 0) {
                    Xvalue.push_back(Module(c[i], c[j]));
                }
                else if (MultiCoor(VectorCoor(c[i], c[j]), XAxis) == 0) {
                    Yvalue.push_back(Module(c[i], c[j]));
                }
                else {
                }
            }
        }
        if (Xvalue.size() == Yvalue.size()) {
            SetRong(Xvalue[0] > Yvalue[0] ? Xvalue[0] : Yvalue[0]);
            SetDai(Xvalue[0] < Yvalue[0] ? Xvalue[0] : Yvalue[0]);
            return true;
        }
        else {
            cout << "Wrong input!\n";
            return false;
        }
    }
    virtual void Xuat() {
        cout << "Hinh chu nhat \n";
        TuGiac::Xuat();
        cout << "\n\t-Chieu rong: " << GetRong() << endl;
        cout << "\n\t-Chieu dai: " << GetDai() << endl;
    }
};

class HV :public HCN
{
private:
    double canh;
public:
    HV() {
        canh = 0;
    }
    HV(double c) {
        canh = c;
    }
    ~HV() { }
    
    void Set() {
        cout << "Nhap hinh vuong" << endl;
        TuGiac::Set();
    }
    void SetCanh(double c) {
        canh = c;
    }
    
    double GetCanh() { return canh; }
    
    virtual bool Check() {
        if (HCN::Check() == 1 && HCN::GetDai() == HCN::GetRong()) {
            SetCanh(HCN::GetDai());
            return true;
        }
        else {
            cout << "Wrong input!\n";
            return false;
        }
    }
    void Xuat() {
        cout << "Hinh vuong \n";
        TuGiac::Xuat();
        cout << "\n\tCanh: " << GetCanh();
    }
};
void Input(vector<TuGiac*>& List) {
    int CatchKey;
    do {
        cout << "\tChon 1 de nhap Hinh Thang.\n";
        cout << "\tChon 2 de nhap Hinh Binh Hanh.\n";
        cout << "\tChon 3 de nhap Hinh Chu Nhat.\n";
        cout << "\tChon 4 de nhap Hinh Vuong.\n";
        cout << "\tChon 5 de quay lai\n";
        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3 && CatchKey != 4 && CatchKey != 5)
        {
            cout << "Chon sai. Vui long chon lai";
        }
        switch (CatchKey)
        {
        case 1:
            List.push_back(new HinhThang);
            List.back()->Set();
            break;
        case 2:
            List.push_back(new HinhBinhHanh);
            List.back()->Set();
            break;
        case 3:
            List.push_back(new HCN);
            List.back()->Set();
            break;
        case 4:
            List.push_back(new HV);
            List.back()->Set();
            break;
        default:
            break;
        }
    } while (CatchKey != 5);
}
void Print(vector<TuGiac*>& List) {
    cout << "-----Xuat ra danh sach hinh tu giac----\n";
    for (int i = 0; i < List.size(); i++) {
        List[i]->Xuat();
        cout << endl;
    }
    cout << "--------------------------\n";
}
int main() {
    vector<TuGiac*> ListQuadrangle;
    ListQuadrangle.resize(0);
    int CatchKey;
    do {
        cout << "Quan li tu giac: \n";
        cout << "\tChon 1 de nhap 1 loai tu giac\n";
        cout << "\tChon 2 de xuat tat cac hinh tu giac\n";
        cout << "\tChon 3 de thoat\n";
        while (cin >> CatchKey && CatchKey != 1 && CatchKey != 2 && CatchKey != 3)
        {
            cout << "Chon sai. Vui long chon lai" << endl;
        }
        switch (CatchKey)
        {
        case 1:
            Input(ListQuadrangle);
            break;
        case 2:
            Print(ListQuadrangle);
            break;
        default:
            break;
        }
    } while (CatchKey != 3);
    for (int i = 0; i < ListQuadrangle.size(); i++) {
        delete ListQuadrangle[i];
    }
    cout << "Thanks!";
    return 0;
}
