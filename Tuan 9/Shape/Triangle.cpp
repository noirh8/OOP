#pragma once
#include "Shape.cpp"
#include <iostream>
using namespace std;
class Triangle : public Shape
{
private:
    const char G = 'G';
    const int num = 3;
public:
    Triangle() {
        setNum(num);
        setSign(G);
    }
    Triangle(const Triangle& tri) {
        setNum(tri.getNum()).setSign(tri.getSign()).setDiem(tri.getDiem());
    }
    ~Triangle() {}
    void Nhap() {
        cout << "Nhap vao 3 diem: ";
        Shape::Nhap();
    }
    void Xuat() {
        cout << "Triangle: "; Shape::Xuat();
        cout << endl;
    }
};
