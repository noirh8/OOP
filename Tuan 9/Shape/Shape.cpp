#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Shape
{
private:
    int num;
    char sign;
    vector<pair<double,double>> Diem;
public:
    Shape() {
        setNum(0).setSign(' ');
        Diem.resize(0);
    }
    Shape(int num, char sign) {
        setNum(num).setSign(sign);
        Diem.resize(getNum());
    }
    Shape(const Shape& shape) {
        setNum(shape.getNum()).setSign(shape.getSign());
        Diem.resize(shape.Diem.size());
        Diem = shape.getDiem();
    }
    ~Shape() {}
    Shape& setNum(int num) {this->num = num;}
    Shape& setSign(char sign) {this->sign = sign;}
    Shape& setDiem(vector<pair<double,double>> arr) {
        Diem.resize(arr.size());
        for(int i=0; i<arr.size(); i++) {
            Diem[i].first = arr[i].first;
            Diem[i].second = arr[i].second;
            return *this;
        }
    }
    int getNum() const {return num;}
    char getSign() const {return sign;}
    vector<pair<double, double>> getDiem() const {return Diem;}
    virtual double getGocTrai() {
        double left = Diem[0].first;
        for(int i=0; i< getNum(); i++) {
            if (left>Diem[i].first) left = Diem[i].first;
        }
        return left;
    }
    virtual double getGocPhai() {
        double right = Diem[0].first;
        for(int i=0; i< getNum(); i++) {
            if (right>Diem[i].first) right = Diem[i].first;
        }
        return right;
    }
    virtual double getGocTren() {
        double top = Diem[0].second;
        for(int i=0; i< getNum(); i++) {
            if (top<Diem[i].second) top = Diem[i].second;
        }
        return top;
    }
    virtual double getGocDuoi() {
        double bottom = Diem[0].second;
        for(int i=0; i< getNum(); i++) {
            if (bottom>Diem[i].second) bottom = Diem[i].second;
        }
        return bottom;
    }
    virtual void Nhap() {
        vector<pair<double,double>> arr;
        arr.resize(0);
        for(int i=0; i<getNum(); i++) {
            cout << "Nhap diem (x,y): ";
            double x,y;
            cin >> x,y;
            arr.push_back(pair<double,double>(x,y));
        }
        setDiem(arr);
    }
    virtual void Xuat() {
        for(int i=0; i< getNum(); i++) {
            cout << "(" << Diem[i].first << "," << Diem[i].second << ") ";
        }
    }
    virtual void NhapFile(istream& file) {
        vector<pair<double,double>> arr;
        arr.resize(0);
        for(int i=0; i<getNum(); i++) {
            double x,y;
            file >> x >> y;
            arr.push_back(pair<double,double>(x,y));
        }
        setDiem(arr);
    }
};
