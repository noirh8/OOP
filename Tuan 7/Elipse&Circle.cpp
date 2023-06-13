#include <iostream>
using namespace std;
class Shape {
public:
    virtual void Xuat() {
        cout << "Thong tin hinh" << endl;
    }
};

class Ellipse : public Shape {
private:
    double TrucLon;  
    double TrucNho;  

public:
Ellipse(double lon, double nho) {
        TrucLon = lon;
        TrucNho = nho;
    }
    void Xuat() override {
        cout << "Hinh Ellipse co truc lon = " << TrucLon << " va truc nho = " << TrucNho << endl;
    }
};

class Circle : public Shape {
private:
    double radius;   
public:
    Circle(double r) {
        radius = r;
    }
    void Xuat() override {
        cout << "Hinh Tron co ban kinh: " << radius << endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong hinh tron va elip: ";
    cin >> n;

    double lon, nho, radius;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin hinh thu " << i + 1 << endl;
        cout << "Nhap truc lon cua elip: ";
        cin >> lon;
        cout << "Nhap truc nho cua elip ";
        cin >> nho;
        cout << "Nhap ban kinh cua tron: ";
        cin >> radius;

        if (lon > 0 && nho > 0) {
            Ellipse ellipse(lon, nho);
            ellipse.Xuat();
        }

        if (radius > 0) {
            Circle circle(radius);
            circle.Xuat();
        }
    }
    return 0;
}
