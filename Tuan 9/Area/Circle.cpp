#include"Shape.cpp"
#include <iostream>
class Circle final : public Shape
{
private:
    const int Edge = 1;

public:
    Circle() {
        SetNumEdge(Edge);
    }
    ~Circle() {}

    void Set() {
        do {
            vector<double> l;
            l.resize(GetNumEdge());
            cout << "Input radius value:";
            cin >> l[0];
            SetLength(l);
            this->CaculateArea();
            this->CaculateCircuit();
        } while (this->Check() == 0);
    }
    
    void Print() {
        cout << "Circle : ";
        Shape::Print();
    }
    void CaculateCircuit() {
        vector<double> l = GetLength();
        SetCircuitValue(l[0] * 2 * 3.14);
    }
    void CaculateArea() {
        vector<double> l = GetLength();
        SetAreaValue(3.1416 * l[0] * l[0]);
    }
    Shape* CreateObject(){
        Shape *Object = new Circle;
        return Object;
    }
    string NameShape() { return "circle"; }
};
