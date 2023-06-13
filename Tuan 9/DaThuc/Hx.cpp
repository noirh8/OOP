#pragma once
#include "Dathuc.cpp"
class Hx : public DaThuc
{
public:
    Hx() {
        vector<double> arr;
        arr.resize(4);
        setBac(3).setHeSo(arr);
    }
    ~Hx() {}
    void setK(double k) {
        vector<double> arr;
        arr.resize(4);
        arr[0] = -5;
        arr[1] = 0;
        arr[2] = k;
        arr[3] = 7;
        setBac(3).setHeSo(arr);
    }
};
