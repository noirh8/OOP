#pragma once
#include "Dathuc.cpp"
class Gx : public DaThuc
{
public:
    Gx() {
        vector<double> arr;
        arr.resize(3);
        setBac(2).setHeSo(arr);
    }
    ~Gx() {}
    void setK(double k) {
        vector<double> arr;
        arr.resize(3);
        arr[0] = 0;
        arr[1] = k;
        arr[2] = -3;
        setBac(2).setHeSo(arr);
    }
};
