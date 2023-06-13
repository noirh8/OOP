#pragma once
#include <iostream>
#include "Dathuc.cpp"
class Fx : public DaThuc
{
public:
    Fx() {
        vector<double> arr;
        arr.resize(2);
        setBac(1).setHeSo(arr);
    }
    ~Fx() {}
    void setK(double k) {
        vector<double> arr;
        arr.resize(2);
        arr[0]= -3;
        arr[1] = k;
        setBac(1).setHeSo(arr);
    }
};
