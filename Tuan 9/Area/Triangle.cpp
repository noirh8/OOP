#include"Shape.cpp"
#include <iostream>
#include <math.h>
using namespace std;
class Triangle final : public Shape
{
private:
    const int Edge = 3;

public:
    Triangle() {
        SetNumEdge(Edge);
    }
    ~Triangle() {}

    void Print() {
        cout << "Triangle : ";
        Shape::Print();
    }
    bool Check() {
        vector<double> l = GetLength();
        if (l[0] + l[1] <= l[2] || l[0] + l[2] <= l[1] || l[1] + l[2] <= l[0])
        {
            cout << "Wrong input!Again.\n";
            return false;
        }
        return true;
    }
    void CaculateArea() {
        vector<double> l = GetLength();
        double p = (l[0] + l[1] + l[2]) / 2;
        SetAreaValue(sqrt(p * (p - l[0]) * (p - l[1]) * (p - l[2])));
    }
    Shape *CreateObject() {
        Shape *Object = new Triangle;
        return Object;
    }
    string NameShape() { return "triangle"; }
};
