#include<iostream>
#include"Diem.h"
#include"Diem.cpp"
#include"TamGiac.h"
#include"TamGiac.cpp"
using namespace std;

int main()
{
    Triangle ABC;
    ABC.InputTrian();
    cout << "3 apices of Trianle: " << endl;
    ABC.OutputTrian();
    cout << endl;
    ABC.TranslationTrian();
    cout << endl;
    ABC.RotateTrian();
    cout << endl;
    ABC.ZoomInOut();
    cout << "3 apices after zoom: " << endl;
    ABC.OutputTrian();

    return 0;
}
