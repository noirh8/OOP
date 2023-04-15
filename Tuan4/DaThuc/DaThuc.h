#pragma once
#include<iostream>
using namespace std;
class DaThuc
{
private:
   
public:
    double* x; //arry of Element
    int NumberOfElement;
    DaThuc();
    DaThuc(int n);
    DaThuc(const DaThuc& DT);
    DaThuc& operator=(const DaThuc& DT);
    double evaluate_polynomial(double*, int, double);
    friend DaThuc operator+(const DaThuc& DT1, const DaThuc& DT2);
    friend DaThuc operator-(const DaThuc& DT1, const DaThuc& DT2);
    friend DaThuc operator*(const DaThuc& DT1, const DaThuc& DT2);
    friend ostream& operator << (ostream& os, DaThuc& DT);
    friend istream& operator >> (istream& is, DaThuc& DT);
    bool PreAllZero(int k) {
        for (int i = NumberOfElement; i >= 0; i--) {
            if (i > k && x[i] != 0) {
                return false;
            }
        }
        return true;
    }
    ~DaThuc();
};
