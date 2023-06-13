#include <iostream>
#include "CoverRec.cpp"
#include "Shape.cpp"
#include "Triangle.cpp"
#include "Rectangle.cpp"
#include "Circle.cpp"
#include "Square.cpp"

using namespace std;
 int main(){
    CoverRectangle CoverShape;
    cout << "Tim hinh chu nhat bao quanh: \n";
    int CatchKey;
    do{
        cout << "1.Nhap tat ca cac hinh can cover\n";
        cout << "2.Nhap tat ca cac hinh bang file\n";
        cout << "3.Xuat tat ca hinh\n";
        cout << "4.Xuat hinh chu nhat can tim\n";
        cout << "5.Thoat\n";
        cout << "Press: ";
        while(cin>>CatchKey&& CatchKey!=1&CatchKey!=2&&CatchKey!=3&&CatchKey!=4&&CatchKey!=5){
            cout << "Chon sai. Vui long chon lai ";
        }
        switch (CatchKey)
        {
        case 1:
            CoverShape.NhapShape();
            break;
        case 2:
            CoverShape.NhapFile();
            break;
        case 3:
            CoverShape.XuatAll();
            break;
        case 4:
            CoverShape.XuatRecCover();
            break;
        default:
            break;
        }
    } while (CatchKey!=5);
 }
