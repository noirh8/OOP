#pragma once
#include<vector>
#include<string>
using namespace std;
class Shape
{
private:
    double AreaValue;
    double CircuitValue;
    int NumEdge;
    vector<double> Length;
public:
    Shape() {
        vector<double> l;
        l.resize(0);
        SetNumEdge(0).SetLength(l);
    }
    Shape(int num) {
        vector<double> l;
        l.resize(num);
        SetNumEdge(num).SetLength(l);
    }
    virtual ~Shape() {}
    
    double GetAreaValue() const { return AreaValue; }
    int GetNumEdge() const { return NumEdge; }
    vector<double> GetLength()const { return Length; }
    
    Shape &SetAreaValue(double areavalue) {
        this->AreaValue = areavalue;
    }
    Shape &SetCircuitValue(double circuitvalue) {
        this->CircuitValue = circuitvalue;
    }
    Shape &SetNumEdge(int numedge) {
        this->NumEdge = numedge;
    }
    Shape &SetLength(vector<double> length) {
        this->Length = length;
    }
    double GetCircuitValue() { return CircuitValue; }
    virtual void Set() {
        do {
            vector<double> l;
            l.resize(GetNumEdge());
            for (int i = 0; i < GetNumEdge(); i++) {
                cout << "Input length of edge " << i + 1 << " : ";
                cin >> l[i];
            }
            SetLength(l);
            this->CaculateArea();
            this->CaculateCircuit();
        } while(this->Check() ==0);
    }
    
    virtual void Print() {
        cout << "( ";
        for (int i = 0; i < GetNumEdge(); i++) {
            cout << Length[i];
            if (i != GetNumEdge() - 1) {
                cout << " , ";
            }
        }
        cout << ") has Shape = " << GetAreaValue() << " and circuit = " << GetCircuitValue();
    }
    virtual bool Check() {
        vector<double> l;
        l = GetLength();
        for (int i = 0; i < GetNumEdge(); i++) {
            if (l[i] == 0) {
                cout << "Wrong input!Again.\n";
                return false;
            }
        }
        return true;
    }
    virtual string NameShape() = 0;
    virtual Shape *CreateObject() = 0;
    virtual void CaculateArea() = 0;
    virtual void CaculateCircuit() {
        double circuit = 0;
        vector<double> l = GetLength();
        for (int i = 0; i < GetNumEdge(); i++) {
            circuit += l[i];
        }
        SetCircuitValue(circuit);
    }
};
