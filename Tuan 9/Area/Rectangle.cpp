#pragma once
#include <iostream>
#include"Shape.cpp"
using namespace std;
class Rectangle final : public Shape
{
private:
    const int Edge = 2;

public:
    Rectangle() {
        SetNumEdge(Edge);
    }
    ~Rectangle() {}

    void Set() {
        do {
            vector<double> l;
            l.resize(GetNumEdge());
            cout << "Input width:";
            cin >> l[0];
            cout << "Input length:";
            cin >> l[1];
            SetLength(l);
            this->CaculateArea();
            this->CaculateCircuit();
        } while (this->Check() == 0);
    }
   
    void Print() {
        cout << "Rectangle : ";
        Shape::Print();
    }
    void CaculateArea() {
        vector<double> l = GetLength();
        SetAreaValue(l[0] * l[1]);
    }
    void CaculateCircuit() {
        vector<double> l = GetLength();
        SetCircuitValue(l[0] * 2 + l[1] * 2);
    }
    Shape *CreateObject() {
        Shape *Object = new Rectangle;
        return Object;
    }
    string NameShape() { return "rectangle"; }
};
