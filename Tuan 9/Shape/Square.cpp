#pragma once 
#include "Shape.cpp"
#include "Rectangle.cpp"
#include <iostream>
using namespace std;
class Square : public Rectangle
{
public:
    Square() {
        setNum(1);
        setSign('V');
    }
    Square(const Square& sqr) {
        setDai(sqr.getDai()).setRong(sqr.getDai()).setDiem(sqr.getDiem());
    }
    ~Square() {}
    void Nhap() {
        cout << "Nhap do dai cua canh: ";
        double dai;
        cin >> dai;
        setDai(dai).setRong(dai);
        cout << "Nhap diem o goc trai: "; 
        Shape::Nhap();
    }
    void Xuat() {
        cout << "Hinh vuong: ";
        Shape::Xuat();
        cout << "- diem goc trai, canh dai = " << getDai() << endl;
    }
    void NhapFile(istream& file) {
        Shape::NhapFile(file);
        double dai;
        file >> dai;
        setDai(dai).setRong(dai);
    }
};
