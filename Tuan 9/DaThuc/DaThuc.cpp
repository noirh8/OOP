#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
class DaThuc
{
private:
    int bac;
    vector<double> HeSo;
public:
    DaThuc() {
        vector<double> arr;
        arr.resize(0);
        setBac(0).setHeSo(arr);
    }
    DaThuc(int deg) {
        vector<double> arr;
        arr.resize(deg + 1);
        setBac(deg).setHeSo(arr);
    }
    DaThuc(const DaThuc& dt) {
        setBac(dt.getBac()).setHeSo(dt.getHeSo());
    }
    ~DaThuc() {}

    DaThuc& setBac(int bac){ this->bac = bac;}
    DaThuc& setHeSo(vector<double> hs) {
        HeSo.resize(hs.size());
        for(int i=0; i<hs.size(); i++) {
            HeSo[i] = hs[i];
        }
        return *this;
    }
    int getBac() const {return bac;}
    vector<double> getHeSo() const {return HeSo;}

    void Nhap() {
        cout << "Nhap bac cua da thuc: ";
        int deg;
        cin >> deg;
        vector<double> arrVal;
        arrVal.resize(deg+1);
        for(int i = 0; i<arrVal.size(); i++) {
            cout << "x^" << i << " = ";
            cin >> arrVal[i];
        }
        setBac(deg).setHeSo(arrVal);
    }
    double CalculateX(double x) {
        vector<double> arr = getHeSo();
        double f = 0;
        for(int i=0; i<=getBac(); i++) {
            f+= arr[i] * pow(x,i);
        }
        return f;
    }
    void KhaoSatDT(double start, double end, double step) {
        ofstream file;
        file.open("KHAOSAT.OUT.txt", ios::app);
        for(double i = start; i<=end; i+=step) {
            file << CalculateX(i) << " ";
        }
        file << endl;
    }
    double DaoHam(double x) {
        vector<double> arr = getHeSo();
        double f = 0;
        if (x == 0)
        {
            f = getHeSo()[1];
            return f;
        }
        for (int i = 0; i <= getBac(); i++)
        {
            f += arr[i] * pow(x, i - 1) * i;
        }
        return f;
    }
    void KhaoSatDaoHam(double start, double end, double step) {
        ofstream file;
        file.open("KHAOSAT.OUT.txt", ios::app);
        for (double i = start; i <= end; i += step)
        {
            file << DaoHam(i) << " ";
        }
        file << endl;
    }
    virtual void setK(double k) = 0;
};
