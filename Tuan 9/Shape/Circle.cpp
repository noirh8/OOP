#pragma once
#include "Shape.cpp"
#include <iostream>
using namespace std;
class Circle : public Shape
{
private:
    const int num = 1;
    const char T = 'T';
    double r;
public: 
    Circle() {
        setNum(num);
        setSign(T);
        setRadius(r);
    }
    Circle(double r) : Shape(num,T) {
        this->r = r;
    }
    Circle(const Circle& cir) {
        setNum(cir.getNum()).setSign(cir.getSign()).setDiem(cir.getDiem());
    }
    Circle& setRadius(double r) {this->r = r;}
    double getRadius() {return r;}
    double getGocTrai() {
        return getDiem()[0].first - getRadius();
    }
    double getGocPhai() {
        return getDiem()[0].first + getRadius();
    }
    double getGocTren() {
        return getDiem()[0].second + getRadius();
    }
    double getGocDuoi() {
        return getDiem()[0].second - getRadius();
    }
    void Nhap() {
        cout << "Nhap ban kinh: ";
        double r;
        cin >> r;
        setRadius(r);
        cout << "Nhap tam hinh tron: ";
        Shape::Nhap();
    }
    void Xuat() {
        cout << "Hinh tron voi toa do tam: ";
        Shape::Xuat();
        cout << ", ban kinh: " << getRadius() << endl;
    }
    void NhapFile(istream& file) {
        Shape::NhapFile(file);
        double r;
        file >> r;
        setRadius(r);
    }
};
