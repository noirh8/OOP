`code()`
#include <iostream>
#include "PhanSo.cpp"
#include "Template.cpp"
using namespace std;
int main() 
{
    int a=3, b=4;
    double c=3.5, d=4.6;
    PS ps1(1,2), ps2(-2,3);
    int intA[4] = {1,-3,5,-2};
    double doubleA[5] = {1.1, 3.5, -2.5, -6.2, 6.8};
    PS psA[3] = {PS(2,3), PS(4,7), PS(-2,5)};
    cout << "Min int a,b: " << Min(a,b) << endl;
    cout << "Max int a,b: " << Max(a,b) << endl;
    cout << "Min double c,d: " << Min(c,d) << endl;
    cout << "Max  double c,d: " << Max(c,d) << endl;
    cout << "Min PS ps1,ps2: " << Min(ps1,ps2);
    cout << "Max PS ps1,ps2: " << Max(ps1,ps2);
    cout << "Max int arr: " << MaxMang(intA,4) << endl;
    cout << "Max double arr: " << MaxMang(doubleA, 5) << endl;
    cout << "Max ps arr: " << MaxMang(psA,3) << endl;
    cout << "Xep int arr: ";
    XepMang(intA,4);
    for(int i=0; i<4; i++) {
        cout << intA[i] << " ";
    }
    cout << "Xep double arr: ";
    XepMang(doubleA,5);
    for(int i=0; i<5; i++) {
        cout << doubleA[i] << " ";
    }
    cout << "Xep ps arr: ";
    XepMang(psA,3);
    for(int i=0; i<3; i++) {
        cout << psA[i] << " ";
    }
    return 0;
}

