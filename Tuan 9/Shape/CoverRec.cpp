#pragma once
#include "Shape.cpp"
#include "Triangle.cpp"
#include "Rectangle.cpp"
#include "Circle.cpp"
#include "Square.cpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class CoverRectangle 
{
private:
    int numShapes;
    vector<Shape*> arrShape;
    Rectangle CoverRec;
public:
    CoverRectangle() {
        arrShape.resize(0);
        numShapes = 0;
    }
    ~CoverRectangle() {
        for(int i=0; i<getNumShapes(); i++) {
            delete arrShape[i];
        }
    }
    CoverRectangle& setNumShape(int n) {
        this->numShapes = n;
    }
    int getNumShapes() const {return numShapes;}
    vector<Shape*> getArrshape() const {return arrShape;}
    void NhapShape() {
        arrShape.resize(0);
        cout << "Nhap so hinh: "; 
        int n; 
        cin >> n;
        setNumShape(n);
        for(int i=0; i<n; i++) {
            cout << "Nhap hinh: " << i+1 << endl;
            cout << "Nhap loai: ";
            char sign;
            cin >> sign;
            switch(toupper(sign)) {
            case 'G':
                arrShape.push_back(new Triangle);
                arrShape.back()->Nhap();
                break;
            case 'C':
                arrShape.push_back(new Rectangle);
                arrShape.back()->Nhap();
                break;
            case 'T':
                arrShape.push_back(new Circle);
                arrShape.back()->Nhap();
                break;
            case 'V':
                arrShape.push_back(new Square);
                arrShape.back()->Nhap();
                break;
            default: break;
            }
        }
    }
    void XuatAll() {
        for(int i=0l; i<getNumShapes(); i++) {
            arrShape[i]->Xuat();
        }
    }
    void setRectangle() {
        double l,r,t,b;
        l = arrShape[0]->getGocTrai();
        l = arrShape[0]->getGocTrai();
        l = arrShape[0]->getGocTrai();
        l = arrShape[0]->getGocTrai();
        double dai, rong;
        for(int i=0; i<getNumShapes(); i++) {
            l = (l>arrShape[i]->getGocTrai()) ? arrShape[i]->getGocTrai() : l;
            r = (r>arrShape[i]->getGocPhai()) ? arrShape[i]->getGocPhai() : r;
            t = (t>arrShape[i]->getGocTren()) ? arrShape[i]->getGocTren() : t;
            b = (b>arrShape[i]->getGocDuoi()) ? arrShape[i]->getGocDuoi() : b;
        }
        vector<pair<double,double>> arr;
        arr.resize(1);
        arr[0] = pair<double, double> (l,t);
        CoverRec.setDai(t-b).setRong(r-l).setDiem(arr);
    }
    void XuatRecCover() {
        setRectangle();
        cout << "HCN cover " << getNumShapes() << " hinh con lai: " << endl;
        CoverRec.Xuat();
        ofstream file;
        file.open("KETQUA.DAT");
        file << CoverRec.getDiem()[0].first << " " << CoverRec.getDiem()[0].second << " " << CoverRec.getDai() << " " << CoverRec.getRong() << endl;
        file.close();
    }
    void NhapFile() {
        arrShape.resize(0);
        ifstream file;
        cout << "Nhap ten file: ";
        string name;
        cin >> name;
        file.open("IPUT.DAT");
        file.open("INPUT.DAT");
    if (!file.is_open())
    {
        cout << "Khong the mo file";
        return;
    }
    int n;
    file >> n;
    setNumShape(n);
    vector<pair<double, double>> arr;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        char sign;
        file >> sign;
        switch (toupper(sign))
        {
        case 'G':
            arrShape.push_back(new Triangle);
            arrShape.back()->NhapFile(file);
            break;
        case 'C':
            arrShape.push_back(new Rectangle);
            arrShape.back()->NhapFile(file);
            break;
        case 'T':
            arrShape.push_back(new Circle);
            arrShape.back()->NhapFile(file);
            break;
        case 'V':
            arrShape.push_back(new Square);
            arrShape.back()->NhapFile(file);
            break;
        default:
            break;
        }
    }
    file.close();
    }
};

