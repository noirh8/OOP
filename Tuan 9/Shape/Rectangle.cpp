#pragma once
#include "Shape.cpp"
#include <iostream>
using namespace std;
class Rectangle : public Shape
{
private:
    const int num = 1;
    const char C = 'C';
    double dai;
    double rong;
public:
    Rectangle() {
        setNum(num);
        setSign(C);
        setDai(0).setRong(0);
    }
    Rectangle(double w, double h) : Shape(num,C) {
        dai = w;
        rong = h;
    }
    Rectangle(const Rectangle& rec) {
        setNum(rec.getNum()).setSign(rec.getSign()).setDiem(rec.getDiem());
    }
    ~Rectangle() {}
    Rectangle& setDai(double dai) {this->dai = dai;}
    Rectangle& setRong(double rong) {this->rong = rong;}
    double getDai() const {return dai;}
    double getRong() const {return rong;}
    double getGocTrai() {
        return getDiem()[0].first;
    }
    double getGocPhai() {
        return getDiem()[0].first + getDai();
    }
    double getGocTren() {
        return getDiem()[0].second; 
    }
    double getGocDuoi() {
        return getDiem()[0].second - getRong();
    }
    void Nhap() {
        double w,h;
        cout << "Nhap dai: "; cin >> w;
        cout << "Nhap rong: "; cin >> h;
        setDai(w).setRong(h);
        cout << "Nhap diem o goc trai: "; 
        Shape::Nhap();
    }
    void Xuat() {
        cout << "Rectangle: ";
        Shape::Xuat(); 
        cout << "- diem goc trai, dai: " << getDai() << ", rong: " << getRong() << endl;
    }
    void NhapFile(istream& file) {
        Shape::NhapFile(file);
        double w,h;
        file >> w >> h;
        setDai(w).setRong(h);
    }
};
